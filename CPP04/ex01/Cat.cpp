#include "Cat.hpp"

Cat::Cat( void ) :
	Animal("Cat"),
	_brain(new Brain)
{
	std::cout << "Default Cat constructor called" << std::endl;
}

Cat::Cat( const Cat& copy ) :
	Animal(copy)
{
	std::cout << "Copy Cat constructor called" << std::endl;

	_brain = new Brain(*copy._brain);
}

Cat::~Cat( void )
{
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

const Cat&	Cat::operator=( const Cat& copy )
{
	std::cout << "Assignment operator Cat called" << std::endl;
	

	Animal::operator=(copy);

	if (_brain)
		delete _brain;

	_brain = new Brain(*copy._brain);

	return (*this);
}

void	Cat::makeSound( void ) const
{
	std::cout << this->getType() << ": * Meow *" << std::endl;
}
