#include "ScalarConverter.hpp"
#include <limits>
#include <iomanip>

ScalarConverter::ScalarConverter(void)
{
};

ScalarConverter::~ScalarConverter(void)
{
};

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
};

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	if (this != &src)
		*this = src;
	return (*this);
};

bool	ScalarConverter::isDecimalNumeric(std::string &literal)
{
	size_t i = 0;
    if (literal[i] == '+' || literal[i] == '-')
        i++;

    bool dots = false;
    while (literal[i] != '\0') {
        if (!std::isdigit(literal[i])) {
            if (literal[i] == '.' && !dots)
                dots = true;
            else if (literal[i] == 'f' && literal[i + 1] == '\0')
                return true;
            else
                return false;
        }
        i++;
    }
    return true;
};

type	ScalarConverter::forScience(std::string &literal)
{
	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		return (FLOAT);
	else if (literal == "nan" || literal == "+inf" || literal == "-inf")
		return (DOUBLE);
	return (SCIENCE);
};

type	ScalarConverter::getType(std::string &literal)
{
	int	size = literal.length();
	type result = forScience(literal);
	if (size == 1 && !std::isdigit(literal[0]))
		return (CHAR);
	if (result != SCIENCE)
		return (result);
	if  (!isDecimalNumeric(literal))
		return (ERROR);
	if (literal[size - 1] == 'f')
		return (FLOAT);
	if (literal.find('.') != std::string::npos)
		return (DOUBLE);
	return (INT);
};

static bool doubleff(const std::string& str) {
    for (size_t i = 0; i < str.length() - 1; ++i)
        if (str[i] == str[i + 1])
            return true;
    return false;
}

static	bool	isLimitChar(int i)
{
	if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
	{
		std::cout << "char: impossible" << std::endl;
		return (1);
	}
	return (0);
};

static	bool	isLimitInt(int i)
{
	if (i < std::numeric_limits<int>::min() || i > std::numeric_limits<int>::max())
	{
		std::cout << "int: impossible" << std::endl;
		return (1);
	}
	return (0);
};

static	bool	isLimitFloat(float i)
{
	if (i < std::numeric_limits<float>::min() || i > std::numeric_limits<float>::max())
	{
		std::cout << "float: impossible" << std::endl;
		return (1);
	}
	return (0);
};

void	isForScienceOrFun(std::string &literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (doubleff(literal) || literal == "nanf")
		std::cout << "float: " << literal << std::endl;
	else
		std::cout << "float: " << literal << "f" << std::endl;
	std::cout << "double: ";
	if (literal[0] == '+' || literal[0] == '-')
		std::cout.write(literal.c_str(), 4) << std::endl;
	else
		std::cout.write(literal.c_str(), 3) << std::endl;
};

void	ScalarConverter::isChar(std::string &value)
{
	char	ch = value[0];
	int		in = static_cast<int>(ch);
	float	fl = static_cast<float>(ch);
	double	dl = static_cast<double>(ch);
	std::cout << "char: " << ch << std::endl;
	std::cout << "int: " << in << std::endl;
	std::cout << "float: " << fl << std::endl;
	std::cout << "double: " << dl << std::endl;
};

void	ScalarConverter::isError(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
};

void	ScalarConverter::isInt(std::string &value)
{

	int in = atoi(value.c_str());

	if (!isLimitChar(in))
	{
		if (std::isprint(in))
			std::cout << "char: " << static_cast<char>(in) << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	std::cout << "int: " << in << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(in) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(in) << std::endl;
	return ;
};

void	ScalarConverter::isFloat(std::string &literal)
{

	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		isForScienceOrFun(literal);
	else
	{
		float fl = strtof(literal.c_str(), NULL);
		if (!isLimitChar(fl))
		{
			if (std::isprint(static_cast<char>(fl)))
				std::cout << "char: " << static_cast<char>(fl) << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
		}
		if (!isLimitInt(fl))
			std::cout << "int: " << static_cast<int>(fl) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << fl << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(fl) << std::endl;
	}
};

void	ScalarConverter::isDouble(std::string &literal)
{
	if (literal == "nan" || literal == "+inf" || literal == "-inf")
		isForScienceOrFun(literal);
	else
	{
		double dl = atof(literal.c_str());
		if (!isLimitChar(dl))
		{
			if (std::isprint(static_cast<char>(dl)))
				std::cout << "char: " << static_cast<char>(dl) << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
		}
		if (!isLimitInt(dl))
			std::cout << "int: " << static_cast<int>(dl) << std::endl;
		if (!isLimitFloat(dl))
			std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(dl) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << (dl) << std::endl;
	}
};

void ScalarConverter::convert(std::string &variable)
{
	ScalarConverter config;

	int type = config.getType(variable);
	switch (type)
	{
	case 0:
		config.isChar(variable);
		break;
	case 1:
		config.isInt(variable);
		break;
	case 2:
		config.isFloat(variable);
		break;
	case 3:
		config.isDouble(variable);
		break;
	default:
		config.isError();
		break;
	}
};
