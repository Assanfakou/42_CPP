#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << Blue << type << " default constructor\n" << RESET;
}

Cat::Cat(const std::string& type) : Animal(type)
{
	std::cout << Blue << type << " default parametrized constructor\n" << RESET;
}

Cat::Cat(const Cat& obj)
{
	std::cout << Green << type << " copy constructor\n" << RESET;
	this->type = obj.type;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << Green << type << "copy assignement operator\n" << RESET;
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

void Cat::makeSound() const
{
	std::cout << Yellow << "this is cat Meow\n" << RESET;
}

Cat::~Cat()
{
	std::cout << RED << type << " Destructor\n" << RESET;
}
