#ifndef AMATERIA_H
# define AMATERIA_H

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
public:

	AMateria( void );
	AMateria( const std::string& type );
	AMateria( const AMateria& copy );
	virtual ~AMateria( void );

	const AMateria&	operator=( const AMateria& copy );

	const std::string	getType( void ) const;
	virtual AMateria*	clone( void ) const = 0;
	virtual void		use( ICharacter& target );


protected:

	std::string	_type;
};

#endif