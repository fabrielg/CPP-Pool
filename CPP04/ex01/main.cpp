#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define NB_ANIMALS 2

int main(void)
{
	std::cout << "=== Animals Constructor ===" << std::endl;
	Animal*	animals[NB_ANIMALS];

	for (int i = 0; i < NB_ANIMALS; i++)
	{
		if (i % 2)
			animals[i] = new Cat;
		else
			animals[i] = new Dog;
	}

	std::cout << std::endl << "=== Sounds test ===" << std::endl;
	for (int i = 0; i < NB_ANIMALS; i++)
	{
		std::cout << i << ": ";
		animals[i]->makeSound();
	}

	std::cout << std::endl << "=== Animals Destructor ===" << std::endl;
	for (int i = 0; i < NB_ANIMALS; i++)
		delete animals[i];

	std::cout << std::endl << "=== Deep Copy test ===" << std::endl;
	{
		Cat originalCat;
		originalCat.makeSound();

		Cat copyCat(originalCat);

		Cat assignedCat;
		assignedCat = originalCat;
	}

	return 0;
}