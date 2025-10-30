#include "Zombie.hpp"
#include <iostream>

int	main(void)
{
	const int	N = 10;
	Zombie		*horde = zombieHorde(N, "Meeseeks");

	for (int i = 0; i < N; i++)
	{
		std::cout << i << ": ";
		horde[i].announce();
	}

	delete [] horde;
	return (1);
}