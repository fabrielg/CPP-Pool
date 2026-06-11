#pragma once

#include <set>

class Span
{
private:
	unsigned int		_size;
	std::multiset<int>	_set;

	Span();

public:
	Span(int size);
	Span(const Span &copy);
	~Span();

	Span	&operator=(const Span &copy);

	void			addNumber(unsigned int value);
	unsigned int	shortestSpan() const;
	unsigned int	longestSpan() const;
};