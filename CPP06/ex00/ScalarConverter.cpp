#include "ScalarConverter.hpp"

#include <cstdlib>
#include <limits>
#include <iomanip>
#include <cctype>
#include <cmath>

static bool isSpecial(const std::string &value)
{
	return (
		value == "nan" || value == "nanf" ||
		value == "+inf" || value == "-inf" ||
		value == "+inff" || value == "-inff"
	);
}

static bool isChar(const std::string &value)
{
	return (value.length() == 1 && !std::isdigit(value[0]));
}

static bool isInt(const std::string &value)
{
	size_t i = 0;

	if (value[i] == '+' || value[i] == '-')
		i++;

	if (i >= value.length())
		return false;

	while (i < value.length())
	{
		if (!std::isdigit(value[i]))
			return false;
		i++;
	}

	return true;
}

static bool isFloat(const std::string &value)
{
	if (value[value.length() - 1] != 'f')
		return false;

	bool dot = false;
	size_t i = 0;

	if (value[i] == '+' || value[i] == '-')
		i++;

	while (i < value.length() - 1)
	{
		if (value[i] == '.')
		{
			if (dot)
				return false;
			dot = true;
		}
		else if (!std::isdigit(value[i]))
			return false;

		i++;
	}

	return dot;
}

static bool isDouble(const std::string &value)
{
	bool dot = false;
	size_t i = 0;

	if (value[i] == '+' || value[i] == '-')
		i++;

	while (i < value.length())
	{
		if (value[i] == '.')
		{
			if (dot)
				return false;
			dot = true;
		}
		else if (!std::isdigit(value[i]))
			return false;

		i++;
	}

	return dot;
}

ScalarType getType(const std::string &value)
{
	if (value.empty())
		return INVALID;
	if (isSpecial(value))
		return SPECIAL;
	if (isChar(value))
		return CHAR;
	if (isInt(value))
		return INT;
	if (isFloat(value))
		return FLOAT;
	if (isDouble(value))
		return DOUBLE;
	return INVALID;
}

static void printChar(double value)
{
	std::cout << "char: ";

	if (value < 0 || value > 127 || std::isnan(value))
	{
		std::cout << "impossible" << std::endl;
		return;
	}

	char c = static_cast<char>(value);

	if (!std::isprint(c))
	{
		std::cout << "Non displayable" << std::endl;
		return;
	}

	std::cout << "'" << c << "'" << std::endl;
}

static void printInt(double value)
{
	std::cout << "int: ";

	if (std::isnan(value)
		|| value < std::numeric_limits<int>::min()
		|| value > std::numeric_limits<int>::max())
	{
		std::cout << "impossible" << std::endl;
		return;
	}

	std::cout << static_cast<int>(value) << std::endl;
}

static void printFloat(double value)
{
	std::cout << "float: "
				<< std::fixed
				<< std::setprecision(1)
				<< static_cast<float>(value)
				<< "f"
				<< std::endl;
}

static void printDouble(double value)
{
	std::cout << "double: "
				<< std::fixed
				<< std::setprecision(1)
				<< value
				<< std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
	ScalarType type = getType(literal);
	double value;

	if (type == INVALID)
	{
		std::cout << "Invalid literal" << std::endl;
		return;
	}

	if (type == CHAR)
		value = static_cast<double>(literal[0]);
	else
		value = std::strtod(literal.c_str(), NULL);

	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}