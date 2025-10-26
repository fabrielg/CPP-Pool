#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	input;

	do
	{
		std::cin >> input;
		if (std::cin.eof())
			return (0);
		if (input.compare("ADD") == 0)
			phoneBook.addContactByInputs();
		else if (input.compare("SEARCH") == 0)
			phoneBook.displayContacts();
	} while (input.compare("EXIT"));
	return (0);
}