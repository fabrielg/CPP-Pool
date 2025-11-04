#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed
{
public:

	Fixed( void );
	Fixed( Fixed& copy );
	Fixed( const int n );
	Fixed( const float n );
	~Fixed( void );
	const Fixed&	operator=( Fixed& copy );

	int		getRawBits( void ) const;
	void	setRawBits( const int raw);
	float	toFloat( void ) const;
	int		toInt( void ) const;

private:

	static const int	_offset = 8;

	int					_bits;
};

std::ostream	&operator<<(std::ostream &os, Fixed &fixed);

#endif