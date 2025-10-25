#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : contacts(), index(-1)
{}

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
