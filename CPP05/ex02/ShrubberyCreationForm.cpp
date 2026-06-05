#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), _target("ShrubberyCreation")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm(target, 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
	: AForm(copy), _target(copy._target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	if (this != &copy)
	{
		AForm::operator=(copy);
		_target = copy._target;
	}
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!isSigned())
		throw AForm::NotSignedException();

	if (executor.getGrade() > getRequiredGradeExec())
		throw AForm::GradeTooLowException();

	std::ofstream file((_target + "_shrubbery").c_str());
	if (!file.is_open())
		return;

	file <<
		"       _-_\n"
		"    /~~   ~~\\\n"
		" /~~         ~~\\\n"
		"{               }\n"
		" \\  _-     -_  /\n"
		"   ~  \\\\ //  ~\n"
		"_- -   | | _- _\n"
		"  _ -  | |   -_\n"
		"      // \\\\\n";

	file.close();
}
