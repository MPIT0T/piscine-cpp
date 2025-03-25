#include "Span.hpp"

#include <stdexcept>

/* Constructors ************************************************************* */
Span::Span() {}

Span::Span(const int &maxSize) : _maxSize(maxSize) {}

Span::Span(const Span &src)
{
	*this = src;
}

Span::~Span() {}

/* Operators **************************************************************** */
Span &Span::operator=(const Span &src)
{
	return (*this);
}

/* Methods ****************************************************************** */
void Span::addNumber(const int &number)
{
	if (_vector.size() >= _maxSize)
		throw std::runtime_error("Max size already reached");
	_vector.push_back(number);
}

unsigned int Span::shortestSpan()
{
	if (_vector.size() <= 1)
		throw std::runtime_error("Not enough numbers stored");
	
}

unsigned int Span::longestSpan()
{
	if (_vector.size() <= 1)
		throw std::runtime_error("Not enough numbers stored");
	int max = *_vector.begin();
	int min = *_vector.begin();
	for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); ++it)
	{
		if (*it > max)
			max = *it;
		if (*it < min)
			min = *it;
	}
	return (max - min);
}
