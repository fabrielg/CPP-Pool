#include <iostream>

#define DEFAULT_NOISE "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

static void	display_upper_string(std::string message)
{
	for (std::string::iterator it = message.begin(); it != message.end(); it++)
		std::cout << (char) std::toupper(*it);
}

int	main(int argc, char **argv)
{
	std::string	message;

	if (argc > 1 && argv[1])
	{
		for (int i = 1; i < argc; i++)
			message.append(argv[i]);
		display_upper_string(message);
	}
	else
		std::cout << DEFAULT_NOISE;
	std::cout << std::endl;
	return (0);
}