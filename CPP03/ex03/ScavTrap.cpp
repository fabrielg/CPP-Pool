#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap()
{
	this->_name = "ScavTrap";
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDamage = 20;

	std::cout << "Default constructor ScavTrap called" << std::endl;
}

ScavTrap::ScavTrap( const std::string& name ) : ClapTrap(name)
{
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDamage = 20;

	std::cout << "String constructor ScavTrap called" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap& copy ) : ClapTrap(copy)
{
	std::cout << "Copy constructor ScavTrap called" << std::endl;

	*this = copy;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "Destructor ScavTrap called" << std::endl;
}

const ScavTrap&	ScavTrap::operator=( const ScavTrap& copy )
{
	ClapTrap::operator=(copy);
	
	std::cout << "Assignment operator ScavTrap called" << std::endl;

	return (*this);
}

void	ScavTrap::attack( const std::string& target )
{
	if (this->_energyPoint <= 0 || this->_hitPoint <=0)
		return ;
	this->_energyPoint--;
	std::cout	<< "ScavTrap " << this->_name
				<< " attacks " << target
				<< ", causing " << this->_attackDamage
		
				<< " points of damage !" << std::endl;
}

void	ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap " << this->_name
			  << " is now in Gate keeper mode!" << std::endl;
}
