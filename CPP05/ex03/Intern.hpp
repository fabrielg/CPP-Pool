#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern &copy);
	~Intern();

	Intern& operator=(const Intern &copy);

	AForm* makeForm(const std::string& name, const std::string& target);
};

#endif
