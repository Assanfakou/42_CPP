#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	type = "AAnimal";
	std::cout << Blue << type << " default constructor\n" << RESET;
}

AAnimal::AAnimal(const std::string& type)
{
	this->type = type;
	std::cout << Blue << "AAnimal default parametrized constructor\n" << RESET;
}

AAnimal::AAnimal(const AAnimal& other)
{
	this->type = other.type;
	std::cout << Blue << "AAnimal copy constructor\n" << RESET;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
	std::cout << Blue << "AAnimal copy assignement operator\n" << RESET;
	if (this != &other)
		this->type = other.type;
	return *this;
}

const std::string& AAnimal::getType() const
{
	return this->type;
}

void AAnimal::makeSound() const
{
	std::cout << Blue << "this is AAnimal\n" << RESET;
}

AAnimal::~AAnimal()
{
	std::cout << RED << "AAnimal Destructor\n" << RESET;
}
