#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap( void ) :
	_name("ClapTrap"),
	_hitPoint(10),
	_energyPoint(10),
	_attackDamage(10)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap( const std::string& name ) :
	_name(name),
	_hitPoint(10),
	_energyPoint(10),
	_attackDamage(10)
{
	std::cout << "String constructor called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& copy)
{
	std::cout << "Copy constructor called" << std::endl;

	*this = copy;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "Destructor called" << std::endl;
}

const ClapTrap&	ClapTrap::operator=( const ClapTrap& copy )
{
	std::cout << "Assignment operator called" << std::endl;

	this->_name = copy._name;
	this->_hitPoint = copy._hitPoint;
	this->_energyPoint = copy._energyPoint;
	this->_attackDamage = copy._attackDamage;
	
	return (*this);
}

void	ClapTrap::attack( const std::string& target )
{
	if (this->_energyPoint <= 0 || this->_hitPoint <=0)
		return ;
	this->_energyPoint--;
	std::cout	<< "ClapTrap " << this->_name
				<< " attacks " << target
				<< ", causing " << this->_attackDamage
				<< " points of damage !" << std::endl;
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	this->_hitPoint -= amount;
	if (this->_hitPoint < 0)
		this->_hitPoint = 0;
	std::cout	<< "ClapTrap " << this->_name
				<< " took " << amount
				<< " points of damage and now has "
				<< this->_hitPoint << " hit points !" << std::endl;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if (this->_energyPoint <= 0 || this->_hitPoint <= 0)
		return ;
	this->_energyPoint--;
	this->_hitPoint += amount;
	std::cout	<< "ClapTrap " << this->_name
				<< " repairs itself " << amount
				<< " hit points and now has "
				<< this->_hitPoint << " hit points !" << std::endl;
}
