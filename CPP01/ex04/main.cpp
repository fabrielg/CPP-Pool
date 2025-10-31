#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 4)
		return (1);

	std::string		out_name = ((std::string) argv[1]).append(".replace");
	std::ofstream	in(argv[1], std::ios::app);
	std::ofstream	out(out_name.c_str(), std::ios::app);
	
	if (in.is_open())
	{
		std::cout << "Success while opening file " << argv[1] << std::endl;
		in.close();
	}
	else
		std::cout << "Error while opening file " << argv[1] << std::endl;
	return (0);
}