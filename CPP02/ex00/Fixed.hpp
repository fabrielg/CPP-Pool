#ifndef FIXED_H
# define FIXED_H

class Fixed
{
public:

	Fixed( void );
	Fixed( Fixed& copy );
	~Fixed( void );
	const Fixed&	operator=( Fixed& copy );

	int		getRawBits( void ) const;
	void	setRawBits( const int raw);

private:

	static const int	_offset = 8;

	int					_bits;
};

#endif