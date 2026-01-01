#include "Cat.hpp"

Cat::Cat()
{
	type = "Default";
	std::cout << Blue << "default constructor\n" << RESET;
}

Cat::Cat(const std::string& type)
{
	this->type = type;
	std::cout << Blue << "default parametrized constructor\n" << RESET;
}

Cat::Cat(const Cat& obj)
{
	std::cout << Green << "copy constructor\n" << RESET;
	this->type = obj.type;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << Green << "copy assignement operator\n" << RESET;
	if (this != &other)
		this->type = other.type;
	return *this;
}

void Cat::makeSound()
{
	std::cout << Yellow << "this is cat Meow\n" << RESET;
}

Cat::~Cat()
{
	std::cout << RED << "Destructor\n " << RESET;
}
