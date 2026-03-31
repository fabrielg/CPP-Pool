#ifdef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
private:
	const std::string	_name;
	size_t				_grade;

public:
	Bureaucrat( void );
	Bureaucrat( const Bureaucrat& copy );
	~Bureaucrat( void );

	Bureaucrat&	operator=( const Bureaucrat& copy );

	const std::string	getName() const;
	size_t				getGrade() const;
}

#endif