#include <iostream>
#include <string>

#include "iter.hpp"

template <typename T>
void print(const T &value)
{
	std::cout << value << std::endl;
}

template <typename T>
void increment(T &value)
{
	value++;
}

int main()
{
	std::cout << "=== INT ===" << std::endl;

	int ints[] = {1, 2, 3, 4, 5};

	iter(ints, 5, print<int>);

	std::cout << std::endl;

	iter(ints, 5, increment<int>);

	iter(ints, 5, print<int>);

	std::cout << std::endl;

	std::cout << "=== STRING ===" << std::endl;

	std::string strs[] = {
		"hello",
		"world",
		"42"
	};

	iter(strs, 3, print<std::string>);

	return 0;
}