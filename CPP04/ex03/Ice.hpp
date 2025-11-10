#ifndef ICE_H
# define ICE_H

# include "AMateria.hpp"
# include <iostream>

class Ice : public AMateria
{
public:

	Ice( void );
	Ice( const Ice& copy );
	~Ice( void );

	const Ice&	operator=( const Ice& copy );
};

#endif