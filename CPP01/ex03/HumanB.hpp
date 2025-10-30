#ifndef HUMAN_B
# define HUMAN_B

# include <iostream>
# include "Weapon.hpp"

class HumanB
{
	public:

		HumanB( std::string name );

		void	setWeapon( Weapon weapon );

		void	attack( void );

	private:

		std::string	_name;
		Weapon		_weapon;
};

#endif