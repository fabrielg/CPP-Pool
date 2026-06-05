#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << "=== TEST EXECUTION ===" << std::endl;

	Bureaucrat boss("Boss", 1);
	Bureaucrat low("Intern", 150);

	ShrubberyCreationForm shrub("home");
	RobotomyRequestForm robot("Bender");
	PresidentialPardonForm pardon("Arthur Dent");

	std::cout << shrub << std::endl;
	std::cout << robot << std::endl;
	std::cout << pardon << std::endl;

	// Try execute without signing
	std::cout << "\n--- Execute without signing ---" << std::endl;
	boss.executeForm(shrub);

	// Sign forms
	std::cout << "\n--- Signing forms ---" << std::endl;
	boss.signForm(shrub);
	boss.signForm(robot);
	boss.signForm(pardon);

	std::cout << shrub << std::endl;
	std::cout << robot << std::endl;
	std::cout << pardon << std::endl;

	// Low grade execution
	std::cout << "\n--- Low grade execution ---" << std::endl;
	low.executeForm(shrub);

	// Valid executions
	std::cout << "\n--- Valid execution ---" << std::endl;
	boss.executeForm(shrub);
	boss.executeForm(robot);
	boss.executeForm(pardon);

	return 0;
}
