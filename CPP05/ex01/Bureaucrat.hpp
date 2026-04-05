#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class Form;

# define MAX_GRADE 150
# define GRADE_TOO_HIGHT_EXCEPTION	"Grade too high !"
# define GRADE_TOO_LOW_EXCEPTION	"Grade too low !"

class Bureaucrat
{
private:
	const std::string	_name;
	size_t				_grade;

	void	setGrade( size_t grade );

public:
	Bureaucrat( void );
	Bureaucrat( std::string name );
	Bureaucrat( size_t grade );
	Bureaucrat( std::string name, size_t grade );
	Bureaucrat( const Bureaucrat& copy );
	~Bureaucrat( void );

	Bureaucrat&	operator=( const Bureaucrat& copy );
	Bureaucrat&	operator++( void );
	Bureaucrat	operator++( int );
	Bureaucrat&	operator--( void );
	Bureaucrat	operator--( int );

	void				incrementGrade(void);
	void				decrementGrade(void);

	const std::string	getName() const;
	size_t				getGrade() const;

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	void	signForm(Form &form);
};

std::ostream	&operator<<(std::ostream &os, Bureaucrat &b);

#endif