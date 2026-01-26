#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed( void ) : _bits(0)
{}

Fixed::Fixed( const Fixed& copy )
{
	*this = copy;
}

Fixed::Fixed( const int n )
{
	this->_bits = n << this->_offset;
}

Fixed::Fixed( const float n )
{
	this->_bits = (int)roundf(n * (1 << this->_offset));
}

Fixed::~Fixed( void )
{}

Fixed&	Fixed::operator=( const Fixed& copy )
{
	this->_bits = copy.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+( const Fixed& copy ) const
{
	Fixed	out;

	out.setRawBits(this->_bits + copy.getRawBits());
	return (out);
}

Fixed	Fixed::operator-( const Fixed& copy ) const
{
	Fixed	out;

	out.setRawBits(this->_bits - copy.getRawBits());
	return (out);
}

Fixed	Fixed::operator*( const Fixed& copy ) const
{
	Fixed	out;

	out.setRawBits(this->_bits * copy.getRawBits() >> this->_offset);
	return (out);
}

Fixed	Fixed::operator/( const Fixed& other ) const
{
	if (other.getRawBits() == 0)
	{
		std::cerr << "Error: division by zero" << std::endl;
		return Fixed();
	}

	Fixed	out;
	out.setRawBits((this->_bits << _offset) / other._bits);
	return (out);
}

Fixed&	Fixed::operator++( void )
{
	this->_bits++;
	return (*this);
}

Fixed	Fixed::operator++( int )
{
	Fixed	temp = *this;

	++*this;
	return (temp);
}

Fixed&	Fixed::operator--( void )
{
	this->_bits--;
	return (*this);
}

Fixed	Fixed::operator--( int )
{
	Fixed	temp = *this;

	--*this;
	return (temp);
}

bool	Fixed::operator<( const Fixed& copy) const
{
	return (this->_bits < copy.getRawBits());
}

bool	Fixed::operator>( const Fixed& copy) const
{
	return (this->_bits > copy.getRawBits());
}

bool	Fixed::operator<=( const Fixed& copy) const
{
	return (this->_bits <= copy.getRawBits());
}

bool	Fixed::operator>=( const Fixed& copy) const
{
	return (this->_bits >= copy.getRawBits());
}

bool	Fixed::operator==( const Fixed& copy) const
{
	return (this->_bits == copy.getRawBits());
}

bool	Fixed::operator!=( const Fixed& copy) const
{
	return (this->_bits != copy.getRawBits());
}

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}

const Fixed&	Fixed::max( const Fixed& a, const Fixed& b)
{
	return (a >= b ? a : b);
}

Fixed&	Fixed::max( Fixed& a, Fixed& b)
{
	return (a >= b ? a : b);
}

const Fixed&	Fixed::min( const Fixed& a, const Fixed& b)
{
	return (a <= b ? a : b);
}

Fixed&	Fixed::min( Fixed& a, Fixed& b)
{
	return (a <= b ? a : b);
}

int	Fixed::getRawBits( void ) const
{
	return (this->_bits);
}

void	Fixed::setRawBits( const int raw )
{
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
