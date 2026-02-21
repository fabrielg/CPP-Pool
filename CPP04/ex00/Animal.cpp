#include "Animal.hpp"

Animal::Animal( void ) :
	_type("Animal")
{
	std::cout << "Default Animal constructor called" << std::endl;
}

Animal::Animal( const std::string& type ) :
	_type(type)
{
	std::cout << "String Animal constructor called" << std::endl;
}

Animal::Animal( const Animal& copy ) : _type(copy._type)
{
	std::cout << "Copy Animal constructor called" << std::endl;
}

Animal::~Animal( void )
{
	std::cout << "Destructor called" << std::endl;
}

Animal&	Animal::operator=( const Animal& copy )
{
	std::cout << "Assignment operator Animal called" << std::endl;

	if (this == &copy)
		return *this;

	this->_type = copy._type;

	return (*this);
}

std::string	Animal::getType( void ) const
{
	return (this->_type);
}

void	Animal::makeSound( void ) const
{
	std::cout << "* Animal sounds *" << std::endl;
}
