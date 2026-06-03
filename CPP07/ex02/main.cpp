#include <iostream>
#include <string>

#include "Array.hpp"

int main()
{
	std::cout << "=== INT ARRAY ===" << std::endl;

	Array<int> numbers(5);

	for (unsigned int i = 0; i < numbers.size(); i++)
		numbers[i] = i * 10;

	for (unsigned int i = 0; i < numbers.size(); i++)
		std::cout << numbers[i] << std::endl;

	std::cout << std::endl;

	std::cout << "=== COPY TEST ===" << std::endl;

	Array<int> copy(numbers);

	copy[0] = 999;

	std::cout << "Original: " << numbers[0] << std::endl;
	std::cout << "Copy    : " << copy[0] << std::endl;

	std::cout << std::endl;

	std::cout << "=== STRING ARRAY ===" << std::endl;

	Array<std::string> strings(3);

	strings[0] = "Hello";
	strings[1] = "42";
	strings[2] = "World";

	for (unsigned int i = 0; i < strings.size(); i++)
		std::cout << strings[i] << std::endl;

	std::cout << std::endl;

	std::cout << "=== EXCEPTION TEST ===" << std::endl;

	try
	{
		std::cout << numbers[42] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}