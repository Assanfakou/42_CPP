#include "Dog.hpp"

Dog::Dog() : Animal()
{
	type = "Dog";
	std::cout << Green << type << " default constructor\n" << RESET;
}

Dog::Dog(const std::string& type) : Animal(type)
{
	std::cout << Blue << type << " default parametrized constructor\n" << RESET;
}

Dog::Dog(const Dog& anim) : Animal(anim)
{
	std::cout << Green << type << " copy constructor\n" << RESET;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << Green << type << " copy assignement operator\n" << RESET;
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

void Dog::makeSound() const
{
	std::cout << Yellow << "this is Dog wof wof\n" << RESET;
}

Dog::~Dog()
{
	std::cout << Green << type << " Destructor\n" << RESET;
}
