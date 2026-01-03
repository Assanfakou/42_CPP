#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	type = "WrongAnimal";
	std::cout << Blue << type << " default constructor\n" << RESET;
}

WrongAnimal::WrongAnimal(const std::string& type)
{
	this->type = type;
	std::cout << Blue << type << " default parametrized constructor\n" << RESET;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	this->type = other.type;
	std::cout << Green << type << " copy constructor\n" << RESET;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << Green << type << "copy assignement operator\n" << RESET;
	if (this != &other)
		this->type = other.type;
	return *this;
}

const std::string& WrongAnimal::getType() const
{
	return this->type;
}

void WrongAnimal::makeSound() const
{
	std::cout << Yellow << "this is WrongAnimal\n" << RESET;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << RED << "WrongAnimal Destructor\n" << RESET;
}
