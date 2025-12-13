#include <iostream>
#include <fstream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string	filename = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];

	if (s1.empty())
	{
		std::cerr << "Error: s1 cannot be empty" << std::endl;
		return 1;
	}

	std::ifstream	in(filename.c_str());
	if (!in)
	{
		std::cerr << "Error: cannot open in file" << std::endl;
		return 1;
	}

	std::ofstream	out((filename + ".replace").c_str());
	if (!out)
	{
		std::cerr << "Error: cannot open out file" << std::endl;
		return 1;
	}

	std::string	line;
	while (std::getline(in, line))
	{
		size_t	pos = 0;

		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}

		out << line;
		if (!in.eof())
			out << std::endl;
	}

	return 0;
}
