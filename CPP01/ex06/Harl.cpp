#include "Harl.hpp"
#include <iostream>
#include <string>

#define BLUE "\x1b[0;94;49m"
#define YELLOW "\x1b[0;93;49m"
#define RED "\x1b[0;91;49m"
#define RESET "\x1b[0m"

void	Harl::complain( std::string level)
{
	static const char	*levels[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	int	i;

	for (i = 0; i < 4; i++)
	{
		if (!level.compare(levels[i]))
			break ;
	}

	switch (i)
	{
	case 0:
		this->debug();
		// fall through
	case 1:
		this->info();
		// fall through
	case 2:
		this->warning();
		// fall through
	case 3:
		this->error();
		break;
	
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
}

void	Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info( void )
{
	std::cout << BLUE << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << RESET << std::endl;
}

void	Harl::warning( void )
{
	std::cout << YELLOW << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << RESET << std::endl;
}

void	Harl::error( void )
{
	std::cout << RED << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << RESET << std::endl;
}
