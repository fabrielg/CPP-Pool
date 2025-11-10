#include "Cat.hpp"

Cat::Cat( void ) :
	Animal("Cat")
{
	std::cout << "Default Cat constructor called" << std::endl;
}

Cat::Cat( const Cat& copy ) :
	Animal(copy)
{
	std::cout << "Copy Cat constructor called" << std::endl;
}

Cat::~Cat( void )
{
	std::cout << "Cat destructor called" << std::endl;
}

const Cat&	Cat::operator=( const Cat& copy )
{
	std::cout << "Assignment operator Cat called" << std::endl;
	
	Animal::operator=(copy);

	return (*this);
}

void	Cat::makeSound( void ) const
{
	std::cout << this->getType() << ": * Meow *" << std::endl;
}
