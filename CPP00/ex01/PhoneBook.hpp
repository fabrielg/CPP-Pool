#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"
# define MAX_CONTACTS 8

class	PhoneBook
{
	public:
		PhoneBook(void);

		void	addContact(void);
		void	displayContacts(void);
		void	displayContacts(int n);

	private:
		Contact	contacts[MAX_CONTACTS];
		int		index;
};

#endif
