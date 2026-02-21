#include "Character.hpp"

Character::Character( void ) :
	_name("Bob")
{
	for (int i = 0; i < INVENTORY_SIZE; i++)
		_inventory[i] = NULL;
}

Character::Character( const std::string& name ) :
	_name(name)
{
	for (int i = 0; i < INVENTORY_SIZE; i++)
		_inventory[i] = NULL;
}

Character::Character( const Character& copy ) :
	_name(copy._name)
{
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		if (copy._inventory[i])
			_inventory[i] = copy._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

Character::~Character( void )
{
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}

Character&	Character::operator=( const Character& copy )
{
	if (this == &copy)
		return *this;

	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
		_inventory[i] = NULL;
	}

	_name = copy._name;

	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		if (copy._inventory[i])
			_inventory[i] = copy._inventory[i]->clone();
	}

	return *this;
}

const std::string&	Character::getName( void ) const
{
	return (_name);
}

int	Character::_getFirstEmptySlot( void ) const
{
	int	index = 0;

	for (; index < INVENTORY_SIZE && _inventory[index]; index++)
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
