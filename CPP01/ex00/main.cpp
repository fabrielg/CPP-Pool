#include "Zombie.hpp"
#include <iostream>

int	main(void)
{
	Zombie	bob("Bob");
	bob.announce();
	Zombie	*marley = newZombie("Marley");
	marley->announce();
	delete marley;

	randomChump("Bob Marley");
	return (1);
}