#ifndef DIAMONDTRAP_h
# define DIAMONDTRAP_H

# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include <iostream>

class DiamondTrap : public ScavTrap, public FragTrap
{
public:

	DiamondTrap( void );
	DiamondTrap( const std::string& name );
	DiamondTrap( const DiamondTrap& copy );
	~DiamondTrap( void );

	const DiamondTrap&	operator=( const DiamondTrap& copy );

	void	attack( const std::string& target );
	void	whoAmI( void );

private:

	std::string	_name;
};

#endif