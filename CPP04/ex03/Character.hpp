#ifndef CHARACTER_H
# define CHARACTER_H

# include "ICharacter.hpp"
# include "AMateria.hpp"

# define INVENTORY_SIZE 4

class Character : public ICharacter
{
public:

	Character( void );
	Character( const Character& copy );
	~Character( void );

	const Character&	operator=( const Character& copy );

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);


private:

	std::string	_name;
	AMateria*	_inventory[INVENTORY_SIZE];

	int					_getFirstEmptySlot( void ) const;
};

#endif