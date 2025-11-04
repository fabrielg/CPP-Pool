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
	const Fixed&	operator=( const Fixed& copy );

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