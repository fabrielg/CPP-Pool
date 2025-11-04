#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed( void ) : _bits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed& copy )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed( const int n )
{
	std::cout << "Int constructor called" << std::endl;
	this->_bits = n << this->_offset;
}

Fixed::Fixed( const float n )
{
	std::cout << "Float constructor called" << std::endl;
	this->_bits = (int)roundf(n * (1 << this->_offset));
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

std::ostream	&operator<<(std::ostream &os, Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
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

float	Fixed::toFloat( void ) const
{
	return ((float)((float)this->_bits / (float)(1 << this->_offset)));
}

int	Fixed::toInt( void ) const
{
	return (this->_bits >> this->_offset);
}
