#include "ScalarConverter.hpp"

void	ScalarConverter::convert(const std::string &value)
{
	std::cout << value << std::endl;
	std::cout << getType(value) << std::endl;
}

static bool	isSpecial(const std::string &value)
{
	std::string specials[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};

	for (int i = 0; i < 6; i++)
	{
		if (value.compare(specials[i]) == 0)
			return true;
	}
	return false;
}

ScalarType	getType(const std::string &value)
{
	if (isSpecial(value))
		return SPECIAL;
	return INVALID;
}