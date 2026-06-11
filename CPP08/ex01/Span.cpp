#include "Span.hpp"
#include <stdexcept>

Span::Span():
	_size(10)
{}

Span::Span(int size):
	_size(size)
{}

Span::Span(const Span& copy)
{
	*this = copy;
}

Span&	Span::operator=(const Span& copy) {
	_size = copy._size;
	_set = copy._set;
	return (*this);
}

Span::~Span()
{}

void	Span::addNumber(unsigned int value)
{
	if (_set.size() >= _size)
		throw std::length_error("Span is full");
	_set.insert(value);
}

unsigned int	Span::longestSpan() const
{
	if (_set.size() < 2)
		throw std::range_error("Need at least 2 values");
	return *(_set.rbegin()) - *(_set.begin());
}

unsigned int	Span::shortestSpan() const
{
	unsigned int	shortestDistance = 0xFFFFFFFF;

	if (_set.size() < 2)
		throw std::range_error("Need at least 2 values");

	unsigned int	distance;
	std::multiset<int>::const_iterator current = _set.begin();
	std::multiset<int>::const_iterator next = current;
	++next;

	while (next != _set.end())
	{
		distance = *next - *current;

		if (distance == 0)
			return (0);
		else if (distance < shortestDistance)
			shortestDistance = distance;
		
		current = next;
		++next;
	}
	return shortestDistance;
}