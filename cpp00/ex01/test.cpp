#include <iostream>

void func(std::string& name)
{
	name = "hello";
	std::cout << name<< std::endl;
}
int main ()
{
	std::string name = "assan";
	
	func(name);
	std::cout << "after : "<< name<< std::endl;
	
}
