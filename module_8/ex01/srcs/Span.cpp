#include "Span.hpp"
#include <climits>
#include <stdexcept>

Span::Span() {}

Span::Span(const int &maxSize) : _maxSize(maxSize) {}

Span::Span(const Span &src)
{
	*this = src;
}

Span::~Span() {}

Span &Span::operator=(const Span &src)
{
	if (this != &src)
	{
		_vector = src._vector;
		_maxSize = src._maxSize;
	}
	return *this;
}

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

	unsigned int minSpan = UINT_MAX;
	for (size_t i = 1; i < _vector.size(); ++i)
	{
		const unsigned int diff = ABS(_vector[i] - _vector[i - 1]);
		if (diff < minSpan)
			minSpan = diff;
	}
	return minSpan;
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
	return max - min;
}
