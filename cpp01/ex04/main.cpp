#include <iostream>
#include <fstream>
#include <stdlib.h>

int main(int ac, char **av) 
{
	if (ac != 4)
	{
		std::cerr << "Error not enough arguments" << std::endl;
		return (1);
	}
	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	if (s1 == s2)
		return 1;
	if (s1.empty() || s2.empty())
	{
		std::cerr << "String cannot be empty" << std::endl;
		return (1);
	}
	std::ifstream input(filename.c_str());
	if (!input.is_open())
	{
		std::cerr << "failed to open the file" << std::endl;
		return (1);
	}
	std::ofstream output((filename + ".replace").c_str());
	if (!output.is_open()) 
	{
		std::cerr << "failed to create the file" << std::endl;
		return (1);
	}
	std::string line;
	size_t pos;
	while (getline(input, line))
	{
		while ((pos = line.find(s1)) != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
		}
		output << line << '\n';
	}
	input.close(); 
	output.close();
}
