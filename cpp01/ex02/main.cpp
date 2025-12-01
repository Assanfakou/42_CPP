#include <iostream>

int main ()
{
	std::string var = "HI THIS IS BRAIN";
	std::string *stringPTR = &var;
	std::string& stringREF = var;

	std::cout << "The memory address of var : " << &var << std::endl;
	std::cout << "The memory address that stringPTR holds : " << stringPTR << std::endl;
	std::cout << "The memory address that stringREF holds : " << &stringREF << std::endl;

	std::cout << "The value of var : " << var << std::endl;
	std::cout << "The value stringPTR points to : " << *stringPTR << std::endl;
	std::cout << "The value stringREF points to : " << stringREF << std::endl;
} 
