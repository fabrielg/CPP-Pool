#include <iostream>
#include "Serializer.hpp"

int main()
{
	int number = 42;

	Data data;
	data.value = &number;

	Data *originalPtr = &data;

	uintptr_t raw = Serializer::serialize(originalPtr);

	Data *deserializedPtr = Serializer::deserialize(raw);

	std::cout << "Original pointer     : " << originalPtr << std::endl;
	std::cout << "Serialized uintptr_t : " << raw << std::endl;
	std::cout << "Deserialized pointer : " << deserializedPtr << std::endl;

	std::cout << std::endl;

	if (originalPtr == deserializedPtr)
		std::cout << "Pointers are equal!" << std::endl;
	else
		std::cout << "Pointers are NOT equal!" << std::endl;

	std::cout << std::endl;

	int *recoveredValue = reinterpret_cast<int *>(deserializedPtr->value);

	std::cout << "Recovered value address : "
				<< deserializedPtr->value
				<< std::endl;

	std::cout << "Recovered int value     : "
				<< *recoveredValue
				<< std::endl;

	return 0;
}