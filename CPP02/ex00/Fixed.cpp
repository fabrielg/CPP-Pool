#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed( void ) : _bits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed& copy )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

const Fixed&	Fixed::operator=( Fixed& copy )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_bits = copy.getRawBits();
	return (*this);
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_bits);
}

void	Fixed::setRawBits( const int raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_bits = raw;
}
