#pragma once

#include <iostream>

class ScalarConverter
{
public:
	static void	convert(const std::string &value);
};

enum ScalarType
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	SPECIAL,
	INVALID
};

ScalarType	getType(const std::string &value);
