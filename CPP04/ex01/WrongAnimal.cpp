#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) :
	_type("WrongAnimal")
{
	std::cout << "Default WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( const std::string& type ) :
	_type(type)
{
	std::cout << "String WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& copy )
{
	std::cout << "Copy WrongAnimal constructor called" << std::endl;
	*this = copy;
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << "Destructor called" << std::endl;
}

const WrongAnimal&	WrongAnimal::operator=( const WrongAnimal& copy )
{
	std::cout << "Assignment operator WrongAnimal called" << std::endl;

	this->_type = copy._type;

	return (*this);
}

std::string	WrongAnimal::getType( void ) const
{
	return (this->_type);
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "* WrongAnimal sounds *" << std::endl;
}
