#pragma once

#include <iostream>
#include "Types.hpp"
#include <cstdlib>
#include <limits>

class ScalarConverter {
	private:

		type	getType(std::string &literal);
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &src);
		~ScalarConverter(void);
		void	printInfo(std::string &value);
		static	void	isChar(std::string &value);
		static	void	isInt(std::string &value);
		static	void	isFloat(std::string &value);
		static	void	isDouble(std::string &value);
		static	void	isError(void);
		type			forScience(std::string &var);
		bool			isDecimalNumeric(std::string &literal);
	public:
		static void convert(std::string &value);
};