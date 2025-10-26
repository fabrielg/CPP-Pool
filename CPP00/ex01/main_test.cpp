#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	input;

	Contact c("Jimmy", "McGill", "Saul Goodman", "(505) 503-445", "Better Call Saul");
	phoneBook.addContact(c);

	c = Contact("Walter", "White", "Heisenberg", "(505) 248-668", "He cook blue meth");
	phoneBook.addContact(c);

	c = Contact("Jessie", "Pinkman", "Cap'n Cook", "(505) 503-4455", "He does not likes bathtub");
	phoneBook.addContact(c);

	c = Contact("Gustavo", "Fring", "Gus", "(505) 842-5660", "Owner of Los Pollos Hermanos");
	phoneBook.addContact(c);

	c = Contact("Hank", "Schrader", "ASAC Schrader", "(505) 122-3378", "DEA Agent and mineral lover");
	phoneBook.addContact(c);

	c = Contact("Mike", "Ehrmantraut", "Fixer", "(505) 719-0002", "No half measures");
	phoneBook.addContact(c);

	c = Contact("Skyler", "White", "Sky", "(505) 499-2371", "She's the accountant of the family");
	phoneBook.addContact(c);

	c = Contact("Lalo", "Salamanca", "Don Lalo", "(505) 666-9999", "Smiling is his warning");
	phoneBook.addContact(c);

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