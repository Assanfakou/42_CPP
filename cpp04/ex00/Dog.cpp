#include "Dog.hpp"

Dog::Dog()
{
	type = "Default";
	std::cout << Blue << "default constructor\n" << RESET;
}

Dog::Dog(const std::string& type)
{
	this->type = type;
	std::cout << Blue << "default parametrized constructor\n" << RESET;
}

Dog::Dog(const Dog& anim)
{
	this->type = anim.type;
	std::cout << Green << "copy constructor\n" << RESET;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << Green << "copy assignement operator\n" << RESET;
	if (this != &other)
		this->type = other.type;
	return *this;
}

void Dog::makeSound()
{
	std::cout << Blue << "this is Dog wof wof\n" << RESET;
}

Dog::~Dog()
{
	std::cout << RED << "Destructor\n " << RESET;
}
