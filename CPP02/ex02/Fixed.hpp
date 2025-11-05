#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed
{
public:

	Fixed( void );
	Fixed( const Fixed& copy );
	Fixed( const int n );
	Fixed( const float n );
	~Fixed( void );
	
	Fixed&			operator=( const Fixed& copy );
	Fixed			operator+( const Fixed& copy );
	Fixed			operator-( const Fixed& copy );
	Fixed			operator*( const Fixed& copy );
	Fixed			operator/( const Fixed& copy );
	Fixed&			operator++( void );
	Fixed			operator++( int );
	Fixed&			operator--( void );
	Fixed			operator--( int );
	bool			operator<( const Fixed& copy ) const;
	bool			operator>( const Fixed& copy ) const;
	bool			operator<=( const Fixed& copy ) const;
	bool			operator>=( const Fixed& copy ) const;
	bool			operator==( const Fixed& copy ) const;
	bool			operator!=( const Fixed& copy ) const;

	static const Fixed&	max(const Fixed& a, const Fixed& b);
	static Fixed&		max(Fixed& a, Fixed& b);
	static const Fixed&	min(const Fixed& a, const Fixed& b);
	static Fixed&		min(Fixed& a, Fixed& b);

	int		getRawBits( void ) const;
	void	setRawBits( const int raw);
	float	toFloat( void ) const;
	int		toInt( void ) const;

private:

	static const int	_offset = 8;

	int					_bits;
};

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed);

#endif