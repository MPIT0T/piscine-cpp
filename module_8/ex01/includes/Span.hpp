#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

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

private:
	std::vector<int>	_vector;
	unsigned int		_maxSize;

	Span();
};



#endif //SPAN_HPP
