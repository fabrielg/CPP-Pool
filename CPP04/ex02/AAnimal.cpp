#include "AAnimal.hpp"

AAnimal::AAnimal( void ) :
	_type("AAnimal")
{
	std::cout << "Default AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal( const std::string& type ) :
	_type(type)
{
	std::cout << "String AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal( const AAnimal& copy )
{
	std::cout << "Copy AAnimal constructor called" << std::endl;
	*this = copy;
}

AAnimal::~AAnimal( void )
{
	std::cout << "Destructor called" << std::endl;
}

const AAnimal&	AAnimal::operator=( const AAnimal& copy )
{
	std::cout << "Assignment operator AAnimal called" << std::endl;

	this->_type = copy._type;

	return (*this);
}

std::string	AAnimal::getType( void ) const
{
	return (this->_type);
}
