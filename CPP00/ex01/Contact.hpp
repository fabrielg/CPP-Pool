#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>

class	Contact
{
	public:
		Contact(void);
		Contact(
			std::string	firstName,
			std::string	lastName,
			std::string	nickName,
			std::string	phoneNumber,
			std::string	secret
		);

		std::string	getFirstName(void);
		void		setFirstName(std::string firstName);
		std::string	getLastName(void);
		void		setLastName(std::string lastName);
		std::string	getNickName(void);
		void		setNickName(std::string nickName);
		std::string	getPhoneNumber(void);
		void		setPhoneNumber(std::string phoneNumber);
		std::string	getSecret(void);
		void		setSecret(std::string secret);

	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	secret;
};

std::ostream	&operator<<(std::ostream &os, Contact &c);

#endif