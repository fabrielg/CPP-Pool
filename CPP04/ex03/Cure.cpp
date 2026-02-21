#include "Cure.hpp"

Cure::Cure( void ) :
	AMateria("cure")
{}

Cure::Cure( const Cure& copy ) :
	AMateria(copy)
{}

Cure::~Cure( void )
{}

Cure&	Cure::operator=( const Cure& copy )
{
	AMateria::operator=(copy);
	return (*this);
}

AMateria*	Cure::clone( void ) const
{
	return (new Cure(*this));
}

void	Cure::use( ICharacter& target )
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
