#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>

class ClapTrap
{
public:

	ClapTrap( void );
	ClapTrap( const std::string& name);
	ClapTrap( const ClapTrap& copy );
	~ClapTrap( void );

	const ClapTrap&	operator=( const ClapTrap& copy );

	void	attack( const std::string& target );
	void	takeDamage( unsigned int amount );
	void	beRepaired( unsigned int amount );


private:

	std::string	_name;
	int			_hitPoint;
	int			_energyPoint;
	int			_attackDamage;
};

#endif