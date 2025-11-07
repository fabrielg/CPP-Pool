#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap()
{
	this->_name = "FragTrap";
	this->_hitPoint = 100;
	this->_energyPoint = 100;
	this->_attackDamage = 30;

	std::cout << "Default constructor FragTrap called" << std::endl;
}

FragTrap::FragTrap( const std::string& name ) : ClapTrap(name)
{
	this->_hitPoint = 100;
	this->_energyPoint = 100;
	this->_attackDamage = 30;
	
	std::cout << "String constructor FragTrap called" << std::endl;
}

FragTrap::FragTrap( const FragTrap& copy ) : ClapTrap(copy)
{
	std::cout << "Copy constructor FragTrap called" << std::endl;

	*this = copy;
}

FragTrap::~FragTrap( void )
{
	std::cout << "Destructor FragTrap called" << std::endl;
}

const FragTrap&	FragTrap::operator=( const FragTrap& copy )
{
	ClapTrap::operator=(copy);
	
	std::cout << "Assignment operator FragTrap called" << std::endl;

	return (*this);
}

void	FragTrap::highFivesGuys( void )
{
	std::cout << "<" << _name << "> ヘ( ^o^)ノ＼(^_^ )" << std::endl;
}
