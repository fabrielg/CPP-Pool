#include "Cat.hpp"

Cat::Cat( void ) :
	AAnimal("Cat"),
	_brain(new Brain)
{
	std::cout << "Default Cat constructor called" << std::endl;
}

Cat::Cat( const Cat& copy ) :
	AAnimal(copy)
{
	std::cout << "Copy Cat constructor called" << std::endl;

	_brain = new Brain(*copy._brain);
}

Cat::~Cat( void )
{
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

Cat&	Cat::operator=( const Cat& copy )
{
	std::cout << "Assignment operator Cat called" << std::endl;
	
	if (this == &copy)
		return *this;

	AAnimal::operator=(copy);

	if (_brain)
		delete _brain;

	_brain = new Brain(*copy._brain);

	return (*this);
}

void	Cat::makeSound( void ) const
{
	std::cout << this->getType() << ": * Meow *" << std::endl;
}

Brain*	Cat::getBrain( void ) const
{
	return _brain;
}
