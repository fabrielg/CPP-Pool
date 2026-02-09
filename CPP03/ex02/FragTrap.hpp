#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:

	FragTrap( void );
	FragTrap( const std::string& name );
	FragTrap( const FragTrap& copy );
	~FragTrap( void );

	FragTrap&	operator=( const FragTrap& copy );

	void	highFivesGuys( void );
};

#endif