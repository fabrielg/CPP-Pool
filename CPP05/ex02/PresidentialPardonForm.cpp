#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
	: AForm(copy), _target(copy._target)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	if (this != &copy)
	{
		AForm::operator=(copy);
		_target = copy._target;
	}
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!isSigned())
		throw AForm::NotSignedException();

	if (executor.getGrade() > getRequiredGradeExec())
		throw AForm::GradeTooLowException();

	std::cout << _target
			  << " has been pardoned by Zaphod Beeblebrox."
			  << std::endl;
}
