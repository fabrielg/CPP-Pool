#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

int	main(void)
{
	/*Contact c("Jimmy", "McGill", "Saul Goodman", "(505) 503-445", "Better Call Saul");
	std::cout << c;
	PhoneBook	phoneBook;
	phoneBook.displayContacts();*/
	PhoneBook	phoneBook;
	std::string	input;

	do
	{
		std::cin >> input;
		if (input.compare("ADD") == 0)
			phoneBook.addContact();
		else if (input.compare("SEARCH") == 0)
			phoneBook.displayContacts();
	} while (input.compare("EXIT"));
	return (0);
}