#include "Contact.hpp"
#include <iostream>

int	main(void)
{
	Contact c("Jimmy", "McGill", "Saul Goodman", "(505) 503-445", "Better Call Saul");
	std::cout << c;
	return (0);
}