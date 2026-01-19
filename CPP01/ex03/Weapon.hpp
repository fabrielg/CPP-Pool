#ifndef WEAPON_H
# define WEAPON_H

# include <iostream>

class Weapon
{

	public:

		Weapon( void );
		Weapon( std::string type );

		const std::string	getType( void ) const;
		void		setType( std::string type );

	private:

		std::string	_type;
};

#endif