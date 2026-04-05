#ifndef FORM_H
# define FORM_H

# include <iostream>

class Form
{
private:
	const std::string	_name;
	bool				_signed;
	const size_t		_gradeCanSign;
	const size_t		_gradeCanExec;

public:
	Form( void );
	Form( const Form &copy );
	~Form( void );

	Form	&operator=( const Form &copy );

	const std::string	getName( void ) const;
	bool				isSigned( void ) const;
	const size_t		getRequiredGradeSign( void ) const;
	const std::string	getRequiredGradeExec( void ) const;

	void				sign( void );

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