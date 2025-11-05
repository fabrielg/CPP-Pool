#include "ClapTrap.hpp"
#include <iostream>

int	main(void)
{
	ClapTrap	bob("bob");

	bob.attack("marley");
	bob.attack("marley");
	bob.attack("marley");
	bob.takeDamage(2);
	bob.takeDamage(1);
	bob.beRepaired(2);
	bob.attack("marley");
	bob.attack("marley");
	bob.takeDamage(4);
	bob.takeDamage(3);
	bob.beRepaired(3);
	bob.takeDamage(3);
	bob.takeDamage(8);
	bob.beRepaired(10);
	bob.attack("marley");
	bob.attack("marley");

	std::cout << "Here, bob can't attack or repair itself anymore :/" << std::endl;

	bob.attack("marley");
	bob.attack("marley");
	bob.attack("marley");
	bob.beRepaired(8);

	return 0;
}