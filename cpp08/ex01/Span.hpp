#pragma once

#include <vector>
#include <algorithm>
#include <iostream>

class Span
{
	private:
		unsigned int n;
		std::vector<int> store;
	public:
		Span(void);
		Span(unsigned int n);
		Span(Span const & obj);
		Span & operator=(Span const & obj);
		~Span(void);

		void addNumber(unsigned int i);
		void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int shortestSpan(void);
		int longestSpan(void);

};