#ifndef AFORM_H
# define AFORM_H

# include <iostream>
# include "Bureaucrat.hpp"

# define NOT_SIGNED_EXCEPTION "Not signed !"

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	bool				_signed;
	const size_t		_gradeCanSign;
	const size_t		_gradeCanExec;

public:
	AForm( void );
	AForm( const std::string name, int gradeSign, int gradeExec );
	AForm( const AForm &copy );
	virtual ~AForm( void );

	AForm	&operator=( const AForm &copy );

	const std::string	getName( void ) const;
	bool				isSigned( void ) const;
	size_t		getRequiredGradeSign( void ) const;
	size_t		getRequiredGradeExec( void ) const;

	void	beSigned(Bureaucrat &b);
	virtual void	execute(Bureaucrat const & executor) const = 0;

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

	class NotSignedException: public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};

std::ostream	&operator<<( std::ostream &os, AForm &f);

#endif