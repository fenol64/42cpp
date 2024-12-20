#pragma once

#include <iostream>
#include <map>
#include <fstream>

class BitcoinExchange
{
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& src);
        BitcoinExchange &operator = (const BitcoinExchange &src);
        void getExchange(std::ifstream &f);
        void dataInsert(const char * path);
        char *pathFile;
        int checkValue(double value);
        int checkLine(std::string line);
        int checkKey(std::string key);

    private:
        std::map<std::string, double> exchangeDataBase;
};
