#include "Animal.hpp"

Animal::Animal()
{
	type = "Animal";
	std::cout << Blue << type << " default constructor\n" << RESET;
}

Animal::Animal(const std::string& type)
{
	this->type = type;
	std::cout << Blue << type << " default parametrized constructor\n" << RESET;
}

Animal::Animal(const Animal& other)
{
	this->type = other.type;
	std::cout << Green << type << " copy constructor\n" << RESET;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << Green << type << "copy assignement operator\n" << RESET;
	if (this != &other)
		this->type = other.type;
	return *this;
}

const std::string& Animal::getType() const
{
	return this->type;
}

void Animal::makeSound() const
{
	std::cout << Blue << "this is Animal\n" << RESET;
}

Animal::~Animal()
{
	std::cout << RED << "Animal Destructor\n" << RESET;
}
