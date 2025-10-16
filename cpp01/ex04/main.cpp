#include <iostream>
#include <fstream>
#include <string.h>

int main(int ac, char **av)
{
	(void) ac;
	std::string get;	
	std::string res;
	
	
	std::ifstream readFile(av[1]);
	if (!readFile)
	{
		std::cout << "Error openning file" << std::endl;
		return 1;
	}
	while (std::getline(readFile, get))
	{
		res.append("\n");
		res.append(get);
	}
	
	ssize_t n = res.find(av[2]);
	if (n > 0)
	{
		res.replace(n, strlen(av[2]), av[3]);
		std::cout << "there is at " << n  << std::endl;
		std::cout << res << std::endl;
	}
		

/*
	std::cout << res << std::endl;
*/

	
	readFile.close();
/*
	std::ofstream Myfile("hello.txt");
	Myfile << "hello here\n";
	Myfile.close();
*/
}
