#ifndef ICE_H
# define ICE_H

# include "AMateria.hpp"

class Ice : public AMateria
{
public:

	Ice( void );
	Ice( const Ice& copy );
	~Ice( void );

	Ice&	operator=( const Ice& copy );

	AMateria*	clone( void ) const;
	void		use( ICharacter& target );
};

#endif