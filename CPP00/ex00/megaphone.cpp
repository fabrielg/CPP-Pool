#include <iostream>
#include <algorithm>
using namespace std;

#define DEFAULT_NOISE "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int	main(int argc, char **argv)
{
	string	message;

	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
			message.append(argv[i]);
		transform(message.begin(), message.end(), message.begin(), ::toupper);
		cout << message;
	}
	else
		cout << DEFAULT_NOISE;
	cout << endl;
	return (0);
}