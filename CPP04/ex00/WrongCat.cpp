#include "WrongCat.hpp"

WrongCat::WrongCat( void ) :
	WrongAnimal("WrongCat")
{
	std::cout << "Default WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat( const WrongCat& copy ) :
	WrongAnimal(copy)
{
	std::cout << "Copy WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat( void )
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat&	WrongCat::operator=( const WrongCat& copy )
{
	std::cout << "Assignment operator WrongCat called" << std::endl;

	if (this == &copy)
		return *this;

	WrongAnimal::operator=(copy);

	return (*this);
}

void	WrongCat::makeSound( void ) const
{
	std::cout << "* Meowww (but wrong) *" << std::endl;
}
