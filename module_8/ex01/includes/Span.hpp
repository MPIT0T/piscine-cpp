#ifndef SPAN_HPP
# define SPAN_HPP

#include <stdexcept>
# include <vector>
# define ABS(x) ((x) < 0 ? -(x) : (x))

class Span
{
public:
/* Constructors */
	Span(const int &maxSize);
	Span(const Span &src);
	~Span();

/* Operators */
	Span &operator=(const Span &src);
	
/* Methods */
	void addNumber(const int &number);
	unsigned int shortestSpan();
	unsigned int longestSpan();

	template<typename InputIterator>
	void addNumber(InputIterator begin, InputIterator end)
	{
		unsigned int rangeSize = std::distance(begin, end);

		if (_vector.size() + rangeSize > _maxSize)
			throw std::runtime_error("Not enough space to add range");

		_vector.insert(_vector.end(),  begin, end);
	}

private:
	std::vector<int>	_vector;
	unsigned int		_maxSize;

	Span();
};

#endif //SPAN_HPP
