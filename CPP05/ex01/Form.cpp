#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form( void ):
	_name("Form"),
	_signed(false),
	_gradeCanSign(MAX_GRADE),
	_gradeCanExec(MAX_GRADE)
{}

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
	return (*this);
}
