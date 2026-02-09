#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>

class ClapTrap
{
public:

	ClapTrap( void );
	ClapTrap( const std::string& name);
	ClapTrap( const ClapTrap& copy );
	virtual ~ClapTrap( void );

	ClapTrap&	operator=( const ClapTrap& copy );

	virtual void	attack( const std::string& target );
	void			takeDamage( unsigned int amount );
	void			beRepaired( unsigned int amount );


protected:

	std::string		_name;
	unsigned int	_hitPoint;
	unsigned int	_energyPoint;
	unsigned int	_attackDamage;
};

#endif