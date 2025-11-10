#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) :
	ClapTrap("DiamondTrap_clap_name"),
	ScavTrap(),
	FragTrap(),
	_name("DiamondTrap")
{
	this->_hitPoint = FragTrap::_hitPoint;
	this->_energyPoint = ScavTrap::_energyPoint;
	this->_attackDamage = FragTrap::_attackDamage;

	std::cout << "Default constructor DiamondTrap called" << std::endl;
}

DiamondTrap::DiamondTrap( const std::string& name ) :
	ClapTrap(name + "_clap_name"),
	ScavTrap(name),
	FragTrap(name),
	_name(name)
{
	this->_hitPoint = FragTrap::_hitPoint;
	this->_energyPoint = ScavTrap::_energyPoint;
	this->_attackDamage = FragTrap::_attackDamage;

	std::cout << "String constructor DiamondTrap called" << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap& copy ) :
	ClapTrap(copy),
	ScavTrap(copy),
	FragTrap(copy)
{
	std::cout << "Copy constructor DiamondTrap called" << std::endl;
	*this = copy;
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "Destructor DiamondTrap called" << std::endl;
}

const DiamondTrap&	DiamondTrap::operator=( const DiamondTrap& copy )
{
	ClapTrap::operator=(copy);

	this->_name = copy._name;

	std::cout << "Assignment operator DiamondTrap called" << std::endl;

	return (*this);
}

void	DiamondTrap::attack( const std::string& target )
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI( void )
{
	std::cout	<< "My name is " << this->_name << std::endl
				<< "My ClapTrap name is " << ClapTrap::_name << std::endl;
}
