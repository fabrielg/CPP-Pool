#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	{
		std::cout << "\n=== Test polymorphism ===" << std::endl;
		Animal* animal = new Animal();
		Animal* cat = new Cat();
		Animal* dog = new Dog();

		std::cout << "\n=== Test type values ===" << std::endl;
		std::cout << animal->getType() << " " << std::endl;
		std::cout << cat->getType() << " " << std::endl;
		std::cout << dog->getType() << " " << std::endl;

		std::cout << "\n=== Test sound values ===" << std::endl;
		animal->makeSound();
		cat->makeSound();
		dog->makeSound();

		std::cout << "\n=== Delete Animals ===" << std::endl;
		delete animal;
		delete cat;
		delete dog;
	}

	{
		std::cout << "\n=== Test polymorphism ===" << std::endl;
		WrongAnimal* animal = new WrongAnimal();
		WrongAnimal* cat = new WrongCat();

		std::cout << "\n=== Test type values ===" << std::endl;
		std::cout << animal->getType() << " " << std::endl;
		std::cout << cat->getType() << " " << std::endl;

		std::cout << "\n=== Test sound values ===" << std::endl;
		animal->makeSound();
		cat->makeSound();

		std::cout << "\n=== Delete Wrong Animals ===" << std::endl;
		delete animal;
		delete cat;
	}

	return 0;
}