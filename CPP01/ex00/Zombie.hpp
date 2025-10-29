#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>

class Zombie
{
	public:
		Zombie( std::string name );
		~Zombie( void );

		Zombie*	newZombie( std::string name );
		void	announce( void );
		void	randomChump( std::string name );

	private:
		std::string	_name;
};

#endif