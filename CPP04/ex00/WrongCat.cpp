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

const WrongCat&	WrongCat::operator=( const WrongCat& copy )
{
	std::cout << "Assignment operator WrongCat called" << std::endl;
	
	WrongAnimal::operator=(copy);

	return (*this);
}
