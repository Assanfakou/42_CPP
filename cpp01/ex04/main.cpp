#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>

std::string ReplaceString(std::string subject, std::string& search, std::string& replace) 
{
	size_t pos = 0;
	while ((pos = subject.find(search, pos)) != std::string::npos)
	{
		subject.replace(pos, search.length(), replace);
		pos += replace.length();
	}
	return subject;
}

void read_file(std::string& got, std::string av)
{
	bool flag = false;
	std::ifstream readFile(av.c_str());
	std::string line;

	if (!readFile.is_open())
	{
		std::cout << "Error openning file" << std::endl;
		exit(1);
	}
	while (std::getline(readFile, line))
	{
		if (flag)
			got.append("\n");
		flag = true;
		got.append(line);
	}
	readFile.close();
}

int main(int ac, char **av)
{
	std::string bd;	
	std::string res;
	std::string finl;
	std::string file;
	std::string filename;
	size_t n = 0;
	size_t i = 0;
	size_t j = 0;

	if (ac != 4)
	{
		std::cout << "Use : ./run filename s1 s2\n";
		return 1;
	}	
	if (av[2][0] == '\0')
	{
		std::cout << "s1 cannot be empty\n";
		return 1;
	}
	file = av[1];
	filename = file + ".replace";
	read_file(res, file);
	while ((n = res.find(av[2], n)) != std::string::npos)
	{
		j = n;
		bd = res.substr(i, j - i);
		finl.append(bd);
		finl.append(av[3]);
		i = j + strlen(av[2]);
		n = i;
	}
	bd = res.substr(i, res.length());
	finl.append(bd);
	std::ofstream Myfile(filename.c_str());
	if (!Myfile.is_open())
	{
		std::cout << "Error openning file" << std::endl;
		exit(1);
	}
	Myfile << finl;
	Myfile.close();
	return 0;
}
