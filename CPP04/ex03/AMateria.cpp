#include "AMateria.hpp"

AMateria::AMateria( void ) :
	_type("None")
{}

AMateria::AMateria( const std::string& type ) :
	_type(type)
{}


AMateria::AMateria( const AMateria& copy )
{
	*this = copy;
}


AMateria::~AMateria( void )
{}


const AMateria&	AMateria::operator=( const AMateria& copy )
{
	(void)copy;
	return (*this);
}

const std::string	AMateria::getType( void ) const
{
	return (_type);
}


void	AMateria::use( ICharacter& target )
{
	std::cout << "* tries to do something weird to " << target.getName() << " *" << std::endl;
}
