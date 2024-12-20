#include "Span.hpp"

Span::Span(void): n(0)
{
}

Span::Span(unsigned int n): n(n)
{
}

Span::Span(Span const & obj)
{
	*this = obj;
}

Span & Span::operator=(Span const & obj)
{
	if (this != &obj)
	{
		this->n = obj.n;
		this->store = obj.store;
	}
	return *this;
}

Span::~Span(void)
{
}

void Span::addNumber(unsigned int i)
{
	if (store.size() == n)
		throw std::runtime_error("Store is full");
	store.push_back(i);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (store.size() + std::distance(begin, end) > n)
		throw std::runtime_error("Store is full");
	store.insert(store.end(), begin, end);
}

int Span::shortestSpan(void)
{
	if (store.size() < 2)
		throw std::runtime_error("Not enough elements");
	std::sort(store.begin(), store.end());
	int min = store[1] - store[0];
	for (unsigned int i = 2; i < store.size(); i++)
	{
		if (store[i] - store[i - 1] < min)
			min = store[i] - store[i - 1];
	}
	return (min);
}

int Span::longestSpan(void)
{
	if (store.size() < 2)
		throw std::runtime_error("Not enough elements");
	std::sort(store.begin(), store.end());
	return (store[store.size() - 1] - store[0]);
}

