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
