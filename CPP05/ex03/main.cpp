#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Intern intern;

	Bureaucrat boss("Xavier Niel", 1);
	Bureaucrat newbie("Me", 150);

	AForm* f1 = intern.makeForm("shrubbery creation", "home");
	AForm* f2 = intern.makeForm("robotomy request", "Bender");
	AForm* f3 = intern.makeForm("presidential pardon", "Arthur");
	AForm* f4 = intern.makeForm("unknown form", "test");

	std::cout << std::endl;

	if (f1)
	{
		boss.signForm(*f1);
		boss.executeForm(*f1);
		newbie.signForm(*f1);

		std::cout << *f1;

		delete f1;
	}

	std::cout << std::endl;

	if (f2)
	{
		boss.signForm(*f2);
		boss.executeForm(*f2);

		std::cout << *f2;
		
		delete f2;
	}

	std::cout << std::endl;

	if (f3)
	{
		boss.signForm(*f3);
		boss.executeForm(*f3);

		std::cout << *f3;

		delete f3;
	}

	std::cout << std::endl;

	if (f4)
		delete f4;

	std::cout << std::endl;

	return 0;
}
