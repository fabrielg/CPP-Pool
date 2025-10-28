#include "PhoneBook.hpp"
#include "Color.hpp"
#include <stdlib.h>
#include <string>

PhoneBook::PhoneBook(void) : contacts(), index(-1), nbContacts(0)
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
		std::cout << YELLOW << inputs[i] << ": " << RESET;
		do
		{
			std::getline(std::cin, input);
		} while (input.empty() && !std::cin.eof());
		(c.*setters[i])(input);
	}
	addContact(c);
}

void	PhoneBook::addContact(Contact c)
{
	if (this->index < MAX_CONTACTS - 1)
		this->index++;
	else
		this->index = 0;
	this->contacts[this->index] = c;
	if (this->nbContacts < MAX_CONTACTS)
		this->nbContacts++;
}

static std::string	getFormatedString(std::string s)
{
	std::string	result = s;

	if (s.length() >= COLUMN_SIZE)
	{
		s.erase(s.begin() + COLUMN_SIZE - 1, s.end());
		s.push_back('.');
	}
	return (s);
}

void	PhoneBook::displayContact(int index)
{
	if (index < 0 || index > this->nbContacts)
		return ;
	
	std::string	firstName = getFormatedString(this->contacts[index].getFirstName());
	std::string	lastName = getFormatedString(this->contacts[index].getLastName());
	std::string	nickName = getFormatedString(this->contacts[index].getNickName());
	std::cout << "|";
	std::cout.width(COLUMN_SIZE); std::cout << std::right << index;
	std::cout << "|";
	std::cout.width(COLUMN_SIZE); std::cout << std::right  << firstName;
	std::cout << "|";
	std::cout.width(COLUMN_SIZE); std::cout << std::right  << lastName;
	std::cout << "|";
	std::cout.width(COLUMN_SIZE); std::cout << std::right  << nickName;
	std::cout << "|" << std::endl;
}

void	PhoneBook::displayFormatedContacts(void)
{
	std::cout << BLUE_BACKGROUND;
	std::cout << "|";
	std::cout.width(COLUMN_SIZE); std::cout << std::right << "Index";
	std::cout << "|";
	std::cout.width(COLUMN_SIZE); std::cout << std::right << "First Name";
	std::cout << "|";
	std::cout.width(COLUMN_SIZE); std::cout << std::right << "Last Name";
	std::cout << "|";
	std::cout.width(COLUMN_SIZE); std::cout << std::right << "Nickname";
	std::cout << "|" << std::endl;
	std::cout << RESET;
	
	if (this->index < 0 || this->nbContacts == 0)
		return ;

	std::cout << LIGHT_BLUE;
	for (int i = 0; i < this->nbContacts; i++)
		displayContact(i);
	std::cout << RESET;

	std::string	input;
	std::cout << "Enter a Contact index to show informations: "; std::cin >> input;

	int	index = std::atoi(input.c_str());
	if (index < 0 || index > this->nbContacts - 1)
	{
		std::cout << RED << "Contact " << index << " not found" << std::endl << RESET;
		return ;
	}
	std::cout << LIGHT_BLUE << "Contact " << index << std::endl << this->contacts[index] << std::endl << RESET;
}

void	PhoneBook::displayContacts(void)
{
	displayContacts(-1);
}

void	PhoneBook::displayContacts(int n)
{
	if (n < 0 || n >= this->index)
		n = this->index + 1;
	std::cout << " >> Displaying " << n << "/" << this->index + 1  << " << " << std::endl;
	if (this->index < 0)
		return ;
	for (int i = 0; i <= this->index && i < n; i++)
		std::cout << "Contact " << i << std::endl << this->contacts[i] << std::endl;
}
