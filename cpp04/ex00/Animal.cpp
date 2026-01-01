#include "Animal.hpp"

Animal::Animal()
{
	type = "Default";
	std::cout << Blue << "default constructor\n" << RESET;
}

Animal::Animal(const std::string& type)
{
	this->type = type;
	std::cout << Blue << "default parametrized constructor\n" << RESET;
}

Animal::Animal(const Animal& other)
{
	this->type = other.type;
	std::cout << Green << "copy constructor\n" << RESET;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << Green << "copy assignement operator\n" << RESET;
	if (this != &other)
		this->type = other.type;
	return *this;
}

void Animal::makeSound()
{
	std::cout << Blue << "this is Animal\n" << RESET;
}

Animal::~Animal()
{
	std::cout << RED << "Destructor\n " << RESET;
}
