#include "Harl.hpp"
#include <iostream>
#include <string>

#define BLUE "\x1b[0;94;49m"
#define YELLOW "\x1b[0;93;49m"
#define RED "\x1b[0;91;49m"
#define RESET "\x1b[0m"

typedef struct s_map
{
	std::string	key;
	void		(Harl::*value)(void);
}	t_map;

void	Harl::complain( std::string level)
{
	static const t_map	levels[] = {
		(t_map){ "DEBUG", &Harl::debug },
		(t_map){ "INFO", &Harl::info },
		(t_map){ "WARNING", &Harl::warning },
		(t_map){ "ERROR", &Harl::error }
	};
	const int	nb_levels = sizeof(levels) / sizeof(levels[0]);

	for (int i = 0; i < nb_levels; i++)
	{
		t_map	map = levels[i];
		if (!map.key.compare(level))
		{
			(this->*map.value)();
			return ;
		}
	}
}

void	Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info( void )
{
	std::cout << BLUE << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << RESET << std::endl;
}

void	Harl::warning( void )
{
	std::cout << YELLOW << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << RESET << std::endl;
}

void	Harl::error( void )
{
	std::cout << RED << "This is unacceptable! I want to speak to the manager now." << RESET << std::endl;
}
