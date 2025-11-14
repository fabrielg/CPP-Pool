#ifndef CHARACTER_H
# define CHARACTER_H

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
public:

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);


private:

	const std::string	_name;
	AMateria*			_inventory[4];

	int					_getFirstEmptySlot( void ) const;
};

#endif