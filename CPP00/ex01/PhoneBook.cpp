#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : contacts(), index(-1)
{}

void	PhoneBook::addContactByInputs(void)
{
	const char	*inputs[5] = {"First Name", "Last Name", "Nickname", "Phone Number", "Secret"};
	void		(Contact::*setters[5])(std::string) =
	{
		&Contact::setFirstName,
		&Contact::setLastName,
		&Contact::setNickName,
		&Contact::setPhoneNumber,
		&Contact::setSecret
	};
	std::string	input;
	Contact		c;

	for (int i = 0; i < 5; i++)
	{
		std::cout << inputs[i] << ": ";
		std::cin >> input;
		(c.*setters[i])(input);
	}
	addContact(c);
}

void	PhoneBook::addContact(Contact c)
{
	if (this->index < MAX_CONTACTS - 1)
		this->index++;
	this->contacts[this->index] = c;
}

void	PhoneBook::displayContacts(void)
{
	displayContacts(-1);
}

void	PhoneBook::displayContacts(int n)
{
	if (n < 0 || n >= this->index)
		n = this->index + 1;
	std::cout << "Displaying " << n << "/" << this->index + 1 << std::endl;
	if (this->index < 0)
		return ;
	for (int i = 0; i <= this->index && i < n; i++)
		std::cout << "Contact " << i << std::endl << this->contacts[i] << std::endl;
}
