#include "Weapon.hpp"

Weapon::Weapon( void ) : _type("No Weapon")
{}

Weapon::Weapon( std::string type ) : _type(type)
{}

std::string	Weapon::getType( void )
{
	return (_type);
}

void	Weapon::setType( std::string type )
{
	_type = type;
}
