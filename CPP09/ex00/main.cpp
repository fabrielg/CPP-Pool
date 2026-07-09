#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>

#define BTC_MAP std::map<std::string, float>

bool isValidValue(const std::string &str, float &value)
{
	char *end;

	value = std::strtof(str.c_str(), &end);

	if (end == str.c_str())
		return false;

	if (*end != '\0')
		return false;

	return true;
}

bool isLeapYear(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

bool isValidDate(const std::string &date)
{
	if (date.length() != 10)
		return false;

	// YYYY-MM-DD
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
		{
			if (date[i] != '-')
				return false;
		}
		else if (!std::isdigit(date[i]))
			return false;
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (year < 2009)

	if (month < 1 || month > 12)
		return false;

	int daysInMonth[] =
	{
		31, 28, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31
	};

	if (isLeapYear(year))
		daysInMonth[1] = 29;

	if (day < 1 || day > daysInMonth[month - 1])
		return false;

	return true;
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage: ./btc <example_file.txt>" << std::endl;
		return 1;
	}

	std::ifstream	fileData(argv[1]);

	if (fileData.fail())
	{
		std::cout << "Error: could not open (" << argv[1] << ") file." << std::endl;
		return 1;
	}

	// Check header file
	std::string	line;
	getline(fileData, line);
	if (line.compare("date,exchange_rate"))
	{
		std::cout << "Error: the head of file must be \"date,exchange_rate\"" << std::endl;
		fileData.close();
		return 1;
	}

	// Check dates and values and store them
	BTC_MAP datas;
	while (getline(fileData, line))
	{
		size_t comma = line.find(',');

		if (comma == std::string::npos)
		{
			std::cout << "Error: bad line => " << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, comma);
		std::string valueStr = line.substr(comma + 1);

		float value;

		if (!isValidDate(date))
		{
			std::cout << "Error: bad date => " << date << std::endl;
			continue;
		}

		if (!isValidValue(valueStr, value))
		{
			std::cout << "Error: bad value => " << valueStr << std::endl;
			continue;
		}

		datas[date] = value;
	}

	fileData.close();

	return 0;
}