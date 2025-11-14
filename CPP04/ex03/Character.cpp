#include "Character.hpp"

const std::string&	Character::getName( void ) const
{
	return (_name);
}

int	Character::_getFirstEmptySlot( void ) const
{
	int	index;

	for (index = 0; index < 4 && _inventory[index]; index++)
		;
	return (index);
}

void	Character::equip( AMateria* m )
{
	int	index = _getFirstEmptySlot();
	if (index > 4)
		return ;
	
	_inventory[index] = m;
}

void	Character::unequip( int idx )
{
	if (!(0 < idx && idx < 3))
		return ;
	_inventory[idx] = 0;
}


void	Character::use(int idx, ICharacter& target)
{
	if (!(0 < idx && idx < 3))
		return ;
	
	AMateria*	m = _inventory[idx];
	if (!m)
		return ;
	
	m->use(target);
}
