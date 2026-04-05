#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form( void ):
	_name("Form"),
	_signed(false),
	_gradeCanSign(MAX_GRADE),
	_gradeCanExec(MAX_GRADE)
{}

Form::Form(const std::string name, int gradeSign, int gradeExec):
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


Form::~Form( void )
{
	std::cout << "Form " << _name << " has been destroyed" << std::endl;
}

Form::Form(const Form &copy):
	_name(copy._name),
	_signed(copy._signed),
	_gradeCanSign(copy._gradeCanSign),
	_gradeCanExec(copy._gradeCanExec)
{
	*this = copy;
}

Form	&Form::operator=( const Form &copy )
{
	(void)copy;
	return (*this);
}

const std::string	Form::getName() const
{
	return _name;
}

bool	Form::isSigned() const
{
	return _signed;
}

size_t	Form::getRequiredGradeSign() const
{
	return _gradeCanSign;
}

size_t	Form::getRequiredGradeExec() const
{
	return _gradeCanExec;
}

const char  *Form::GradeTooHighException::what() const throw()
{
	return (GRADE_TOO_HIGHT_EXCEPTION);
}

const char  *Form::GradeTooLowException::what() const throw()
{
	return (GRADE_TOO_LOW_EXCEPTION);
}

void	Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > _gradeCanSign)
		throw GradeTooLowException();
	_signed = true;
}

std::ostream	&operator<<(std::ostream &os, Form &f)
{
	os << "Form [" << f.getName() << "]" << std::endl
	<< "signed :" << ( f.isSigned() ? "✅" : "❌" ) << std::endl
	<< "Grade sign: " << f.getRequiredGradeSign() << std::endl
	<< "Grade exec: " << f.getRequiredGradeExec() << std::endl;
	return os;
}
