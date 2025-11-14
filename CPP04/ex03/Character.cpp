#include "Character.hpp"

Character::Character( void ) :
	_name("Bob")
{}

Character::Character( const Character& copy )
{
	*this = copy;
}

Character::~Character( void )
{}

const Character&	Character::operator=( const Character& copy )
{
	_name = copy._name;
	for (int i = 0; i < INVENTORY_SIZE; i++)
		_inventory[i] = copy._inventory[i];
	return (*this);
}

const std::string&	Character::getName( void ) const
{
	return (_name);
}

int	Character::_getFirstEmptySlot( void ) const
{
	int	index;

	for (index = 0; index < INVENTORY_SIZE && _inventory[index]; index++)
		;
	return (index);
}

void	Character::equip( AMateria* m )
{
	int	index = _getFirstEmptySlot();
	if (index >= INVENTORY_SIZE)
		return ;
	
	_inventory[index] = m;
}

void	Character::unequip( int idx )
{
	if (!(0 <= idx && idx < INVENTORY_SIZE))
		return ;
	_inventory[idx] = 0;
}


void	Character::use(int idx, ICharacter& target)
{
	if (!(0 <= idx && idx < INVENTORY_SIZE))
		return ;
	
	AMateria*	m = _inventory[idx];
	if (!m)
		return ;
	
	m->use(target);
}
