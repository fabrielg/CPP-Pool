#include "Zombie.hpp"

Zombie::Zombie( std::string name ) : _name(name)
{}

Zombie::~Zombie( void )
{
	std::cout << this->_name << " is dead." << std::endl;
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
