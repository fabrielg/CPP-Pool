#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b("Jean", 42);

		std::cout << "Initial: " << b << std::endl;

		++b;
		std::cout << "After ++b: " << b << std::endl;

		b++;
		std::cout << "After b++: " << b << std::endl;

		--b;
		std::cout << "After --b: " << b << std::endl;

		b--;
		std::cout << "After b--: " << b << std::endl;

		std::cout << "\n--- Testing limits ---" << std::endl;

		Bureaucrat top("Boss", 1);
		std::cout << top << std::endl;
		++top;
		std::cout << top << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat low("Intern");
		std::cout << low << std::endl;

		--low;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
