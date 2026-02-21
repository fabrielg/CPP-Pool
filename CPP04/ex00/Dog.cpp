#include "Dog.hpp"

Dog::Dog( void ) :
	Animal("Dog")
{
	std::cout << "Default Dog constructor called" << std::endl;
}

Dog::Dog( const Dog& copy ) :
	Animal(copy)
{
	std::cout << "Copy Dog constructor called" << std::endl;
}

Dog::~Dog( void )
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog&	Dog::operator=( const Dog& copy )
{
	std::cout << "Assignment operator Dog called" << std::endl;

	if (this == &copy)
		return *this;

	Animal::operator=(copy);

	return (*this);
}

void	Dog::makeSound( void ) const
{
	std::cout << this->getType() << ": * Woof *" << std::endl;
}
