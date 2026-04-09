#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat( void ) : _name("bureaucrat"), _grade(MAX_GRADE)
{}

Bureaucrat::Bureaucrat( std::string name ): _name(name), _grade(MAX_GRADE)
{}

Bureaucrat::Bureaucrat( size_t grade ): _name("bureaucrat")
{
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat( std::string name, size_t grade ): _name(name)
{
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat( const Bureaucrat &copy ): _name(copy._name)
{
	*this = copy;
}

Bureaucrat &Bureaucrat::operator=( const Bureaucrat &copy )
{
	if (this == &copy)
		return *this;

	this->_grade = copy._grade;
	return *this;
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << "Bureaucrat " << _name << " has been destroyed" << std::endl;
}

const std::string	Bureaucrat::getName( void ) const
{
	return this->_name;
}

size_t	Bureaucrat::getGrade( void ) const
{
	return this->_grade;
}

void    Bureaucrat::setGrade( size_t grade )
{
    if (grade > MAX_GRADE)
        throw GradeTooLowException();
    else if (grade < 1)
        throw GradeTooHighException();
    else
        this->_grade = grade;
}

const char  *Bureaucrat::GradeTooHighException::what() const throw()
{
    return (GRADE_TOO_HIGHT_EXCEPTION);
}

const char  *Bureaucrat::GradeTooLowException::what() const throw()
{
    return (GRADE_TOO_LOW_EXCEPTION);
}

void	Bureaucrat::incrementGrade( void )
{
	this->setGrade(this->_grade - 1);
}

void	Bureaucrat::decrementGrade( void )
{
	this->setGrade(this->_grade + 1);
}

Bureaucrat& Bureaucrat::operator++()
{
	this->incrementGrade();
	return *this;
}

Bureaucrat Bureaucrat::operator++( int )
{
	Bureaucrat tmp = *this;
	++*this;
	return tmp;
}

Bureaucrat& Bureaucrat::operator--( void )
{
	this->decrementGrade();
	return *this;
}

Bureaucrat Bureaucrat::operator--( int )
{
	Bureaucrat tmp = *this;
	--*this;
	return tmp;
}

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " couldn’t sign " << form.getName()
			<< " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _name << " couldn’t execute "
				  << form.getName()
				  << " because " << e.what() << std::endl;
	}
}


std::ostream    &operator<<(std::ostream &os, Bureaucrat &b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
    return os;
}
