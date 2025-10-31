#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
	if (argc != 4)
		return (1);

	std::string		out_name = ((std::string) argv[1]).append(".replace");
	std::ifstream	in(argv[1]);
	std::ofstream	out(out_name.c_str());
	
	if (in.is_open() && out.is_open())
	{
		std::cout << "Success while opening file " << argv[1] << std::endl;

		std::string	content((std::istreambuf_iterator<char>(in)),
							(std::istreambuf_iterator<char>()));

		int	filter_size = ((std::string) argv[2]).size();
		int	last_index = 0;
		int	index = content.find(argv[2]);
		while (index >= 0)
		{
			out << content.substr(last_index, index - last_index);
			out << argv[3];
			last_index = index + filter_size;
			index = content.find(argv[2], last_index);
		}
		out << content.substr(last_index);
		in.close();
		out.close();
	}
	else
	{
		if (!in.is_open())
			std::cout << "Error while opening file " << argv[1] << std::endl;
		if (!out.is_open())
			std::cout << "Error while opening file " << out_name << std::endl;
		return (1);
	}
	return (0);
}