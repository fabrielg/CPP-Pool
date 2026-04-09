#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &copy)
{
	(void)copy;
}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern &copy)
{
	(void)copy;
	return *this;
}

static AForm* createShrubbery(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

static AForm* createPresidential(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
	typedef AForm* (*FormCreator)(const std::string&);

	std::string names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	FormCreator creators[3] = {
		&createShrubbery,
		&createRobotomy,
		&createPresidential
	};

	for (int i = 0; i < 3; i++)
	{
		if (name == names[i])
		{
			AForm* form = creators[i](target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return form;
		}
	}

	std::cout << "Intern couldn’t find the form \"" << name << "\"" << std::endl;
	return NULL;
}
