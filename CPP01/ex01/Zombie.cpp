#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie( void ) : _name("Zombie")
{}

Zombie::Zombie( std::string name ) : _name(name)
{}

Zombie::~Zombie( void )
{
	std::cout << this->_name << " is dead." << std::endl;
}

std::string	Zombie::getName( void )
{
	return (this->_name);
}

void	Zombie::setName( std::string name)
{
	this->_name = name;
}

void	Zombie::announce( void )
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie*	newZombie( std::string name )
{
	return (new Zombie(name));
}

void	randomChump( std::string name )
{
	Zombie	zombie(name);
	zombie.announce();
}

Zombie* zombieHorde( int N, std::string name )
{
	if (N <= 0)
		return (NULL);
	
	Zombie	*horde = new Zombie[N];

	for (int i = 0; i < N; i++)
		horde[i].setName(name);
	
	return (horde);
}
