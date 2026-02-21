#include "Dog.hpp"

Dog::Dog( void ) :
	Animal("Dog"),
	_brain(new Brain)
{
	std::cout << "Default Dog constructor called" << std::endl;
}

Dog::Dog( const Dog& copy ) :
	Animal(copy)
{
	std::cout << "Copy Dog constructor called" << std::endl;
	_brain = new Brain(*copy._brain);
}

Dog::~Dog( void )
{
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

Dog&	Dog::operator=( const Dog& copy )
{
	std::cout << "Assignment operator Dog called" << std::endl;

	if (this == &copy)
		return *this;

	Animal::operator=(copy);

	if (_brain)
		delete _brain;
	
	_brain = new Brain(*copy._brain);

	return (*this);
}

void	Dog::makeSound( void ) const
{
	std::cout << this->getType() << ": * Woof *" << std::endl;
}

Brain*	Dog::getBrain( void ) const
{
	return _brain;
}
