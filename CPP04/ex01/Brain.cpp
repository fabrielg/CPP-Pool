#include "Brain.hpp"

Brain::Brain( void ): _ideas()
{
	std::cout << "Default Brain constructor called" << std::endl;
}

Brain::Brain( const Brain& copy )
{
	std::cout << "Copy Brain constructor called" << std::endl;

	*this = copy;
}

Brain::~Brain( void )
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain&	Brain::operator=( const Brain& copy )
{
	std::cout << "Assignment operator Brain called" << std::endl;

	for (int i = 0; i < 100; i++)
		_ideas[i] = copy._ideas[i];
	return (*this);
}
