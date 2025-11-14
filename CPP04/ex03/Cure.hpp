#ifndef CURE_H
# define CURE_H

# include "AMateria.hpp"

class Cure : public AMateria
{
public:

	Cure( void );
	Cure( const Cure& copy );
	~Cure( void );

	const Cure&	operator=( const Cure& copy );

	AMateria*	clone( void ) const;
	void		use( ICharacter& target );
};

#endif