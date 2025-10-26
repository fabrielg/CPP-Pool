#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"
# define MAX_CONTACTS 8
# define COLUMN_SIZE 10

class	PhoneBook
{
	public:
		PhoneBook(void);

		void	addContactByInputs(void);
		void	addContact(Contact c);
		void	displayFormatedContacts(void);
		void	displayContacts(void);
		void	displayContacts(int n);

	private:
		Contact	contacts[MAX_CONTACTS];
		int		index;

		void	displayContact(int index);
};

#endif
