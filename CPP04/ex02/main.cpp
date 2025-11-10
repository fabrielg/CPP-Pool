#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
	std::cout << "=== Testing abstract AAnimal class ===" << std::endl;

	// AAnimal a; // ❌ This would not compile anymore (abstract class)

	std::cout << "\n=== Creating animals ===" << std::endl;
	AAnimal* cat = new Cat();
	AAnimal* dog = new Dog();

	std::cout << "\n=== Making sounds ===" << std::endl;
	cat->makeSound();
	dog->makeSound();

	std::cout << "\n=== Deleting animals ===" << std::endl;
	delete cat;
	delete dog;

	std::cout << "\n=== Testing stack objects ===" << std::endl;
	Cat kitty;
	Dog rex;

	std::cout << "kitty makes a sound: ";
	kitty.makeSound();

	std::cout << "rex makes a sound: ";
	rex.makeSound();

	return 0;
}
