#pragma once

#include <exception>

class Error : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Error: invalid cast";
		}
};

class ErrorNULL : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Error: NULL pointer";
	}
};