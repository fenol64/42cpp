#include <iostream>
#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <map>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &src)
{
    this->exchangeDataBase = src.exchangeDataBase;
    return *this;
}


BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
    *this = src;
}

void BitcoinExchange::getExchange(std::ifstream &f)
{
    try
    {
        std::string line;
        std::string key;
        double value;
        std::map<std::string, double>::const_iterator cotation;

        std::getline(f, line);
        std::getline(f, line);
        for (;!f.eof(); std::getline(f, line))
        {
            if (checkLine(line))
                continue;
            key = line.substr(0, 10);
            value = std::atof(line.substr(13).c_str());
            if (!checkKey(key) && !checkValue(value))
            {
            cotation = this->exchangeDataBase.lower_bound(key);
            std::cout << key << "=> " << value << " = "
            << cotation->second * value << std::endl;
            }
        }
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

int BitcoinExchange::checkKey(std::string key)
{
    int year = atoi(key.substr(0, 4).c_str());
    int month = atoi(key.substr(5, 2).c_str());
    int day = atoi(key.substr(8, 2).c_str());

    if (year > 2023 || year < 0)
        return 1;
    if (key[4] != '-')
        return 1;
    if (month > 12 || month <= 0)
        return 1;
    if (key[7] != '-')
        return 1;
    if (day > 31 || day < 1)
        return 1;
    return 0;
}

int BitcoinExchange::checkValue(double value)
{
	if (value < 0)
	{
		std::cerr << "Error: not a positive number (" << value << ")" << std::endl;
		return (1);
	}
	else if (value > 1000)
	{
		std::cerr << "Error: too large a number (" << value << ")" << std::endl;
		return (1);
	}
	else
		return (0);
}

int	BitcoinExchange::checkLine(std::string line)
{
	if (line.size() < 14 || line.find('|') == std::string::npos)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return (1);
	}
	return (0);
}

void BitcoinExchange::dataInsert(const char *path)
{
    std::ifstream data(path);
    std::string key;
    float value;
    std::string line;
    const char *joker;

    std::getline(data, line);
    while (std::getline(data, line))
    {
        int i = 0;
        while (isdigit(line[i]) || line[i] == '-')
            i++;
        key = line.substr(0, i);
        i++;
        joker = line.c_str() + i;
        char *endptr;
        value = strtod(joker, &endptr);
        if (*endptr != '\0')
        {
            std::cerr << "Error converting value on line: " << line << std::endl;
            break;
        }
        else
        {
            this->exchangeDataBase.insert(std::pair<std::string, double>(key, value));
        }
    }
}





