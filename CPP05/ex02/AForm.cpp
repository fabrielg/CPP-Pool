#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm( void ):
	_name("Form"),
	_signed(false),
	_gradeCanSign(MAX_GRADE),
	_gradeCanExec(MAX_GRADE)
{}

AForm::AForm(const std::string name, int gradeSign, int gradeExec):
	_name(name),
	_signed(false),
	_gradeCanSign(gradeSign),
	_gradeCanExec(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
		throw GradeTooLowException();
}


AForm::~AForm( void )
{
	std::cout << "Form " << _name << " has been destroyed" << std::endl;
}

AForm::AForm(const AForm &copy):
	_name(copy._name),
	_signed(copy._signed),
	_gradeCanSign(copy._gradeCanSign),
	_gradeCanExec(copy._gradeCanExec)
{
	*this = copy;
}

AForm	&AForm::operator=( const AForm &copy )
{
	(void)copy;
	return (*this);
}

const std::string	AForm::getName() const
{
	return _name;
}

bool	AForm::isSigned() const
{
	return _signed;
}

size_t	AForm::getRequiredGradeSign() const
{
	return _gradeCanSign;
}

size_t	AForm::getRequiredGradeExec() const
{
	return _gradeCanExec;
}

const char  *AForm::GradeTooHighException::what() const throw()
{
	return (GRADE_TOO_HIGHT_EXCEPTION);
}

const char  *AForm::GradeTooLowException::what() const throw()
{
	return (GRADE_TOO_LOW_EXCEPTION);
}

const char  *AForm::NotSignedException::what() const throw()
{
	return (NOT_SIGNED_EXCEPTION);
}

void	AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > _gradeCanSign)
		throw GradeTooLowException();
	_signed = true;
}

std::ostream	&operator<<(std::ostream &os, AForm &f)
{
	os << "Form [" << f.getName() << "]" << std::endl
	<< "signed :" << ( f.isSigned() ? "✅" : "❌" ) << std::endl
	<< "Grade sign: " << f.getRequiredGradeSign() << std::endl
	<< "Grade exec: " << f.getRequiredGradeExec() << std::endl;
	return os;
}
