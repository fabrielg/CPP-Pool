#ifndef FORM_H
# define FORM_H

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_signed;
	const size_t		_gradeCanSign;
	const size_t		_gradeCanExec;

public:
	Form( void );
	Form( const std::string name, int gradeSign, int gradeExec );
	Form( const Form &copy );
	~Form( void );

	Form	&operator=( const Form &copy );

	const std::string	getName( void ) const;
	bool				isSigned( void ) const;
	size_t		getRequiredGradeSign( void ) const;
	size_t		getRequiredGradeExec( void ) const;

	void	beSigned(Bureaucrat &b);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};

	class GradeTooLowException: public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};

std::ostream	&operator<<( std::ostream &os, Form &f);

#endif