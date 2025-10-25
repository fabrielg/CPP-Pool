#include "Contact.hpp"

Contact::Contact(void) : firstName(""), lastName(""), nickName(""), phoneNumber(""), secret("")
{}

Contact::Contact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string secret)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickName = nickName;
	this->phoneNumber = phoneNumber;
	this->secret = secret;
}

std::string	Contact::getFirstName(void)
{
	return (this->firstName);
}

void	Contact::setFirstName(std::string firstName)
{
	this->firstName = firstName;
}

std::string	Contact::getLastName(void)
{
	return (this->lastName);
}

void	Contact::setLastName(std::string lastName)
{
	this->lastName = lastName;
}

std::string	Contact::getNickName(void)
{
	return (this->nickName);
}

void	Contact::setNickName(std::string nickName)
{
	this->nickName = nickName;
}

std::string	Contact::getPhoneNumber(void)
{
	return (this->phoneNumber);
}

void	Contact::setPhoneNumber(std::string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

std::string	Contact::getSecret(void)
{
	return (this->secret);
}

void	Contact::setSecret(std::string secret)
{
	this->secret = secret;
}

std::ostream	&operator<<(std::ostream &os, Contact &c)
{
	os << "FirstName: " << c.getFirstName() << std::endl
	<< "LastName: " << c.getLastName() << std::endl
	<< "NickName: " << c.getNickName() << std::endl
	<< "Phone Number: " << c.getPhoneNumber() << std::endl
	<< "Secret: " << c.getSecret() << std::endl;

	return (os);
}
