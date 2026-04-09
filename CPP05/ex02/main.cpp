#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "=== BASIC TEST ===" << std::endl;

	try
	{
		Bureaucrat bob("Bob", 50);
		Form contract("Contract", 45, 30);

		std::cout << bob << std::endl;
		std::cout << contract << std::endl;

		std::cout << "\n--- Attempt to sign ---" << std::endl;
		bob.signForm(contract);

		std::cout << contract << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== SUCCESS CASE ===" << std::endl;

	try
	{
		Bureaucrat boss("Boss", 1);
		Form topSecret("TopSecret", 10, 5);

		boss.signForm(topSecret);
		std::cout << topSecret << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n=== FAILURE CASE (grade too low) ===" << std::endl;

	try
	{
		Bureaucrat intern("Intern", 150);
		Form important("Important", 50, 20);

		intern.signForm(important);
		std::cout << important << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n=== INVALID FORM CREATION ===" << std::endl;

	try
	{
		Form invalid("Invalid", 0, 200); // throw
	}
	catch (std::exception &e)
	{
		std::cout << "Creation failed: " << e.what() << std::endl;
	}

	return 0;
}
