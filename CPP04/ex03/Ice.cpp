#include "Ice.hpp"

Ice::Ice( void ) :
	AMateria("ice")
{}

Ice::Ice( const Ice& copy ) :
	AMateria(copy)
{}

Ice::~Ice( void )
{}

const Ice&	Ice::operator=( const Ice& copy )
{
	AMateria::operator=(copy);
	return (*this);
}

AMateria*	Ice::clone( void ) const
{
	return (new Ice(*this));
}

void	Ice::use( ICharacter& target )
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
