#include "Dog.hpp"

Dog::Dog() : Animal()
{
	type = "Dog";
	std::cout << Cyan << type << " default constructor\n" << RESET;
	brain = new Brain();
}

Dog::Dog(const Dog& anim) : Animal(anim)
{
	std::cout << Cyan << type << " copy constructor\n" << RESET;
	brain = new Brain(*anim.brain);
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << Cyan << type << " copy assignement operator\n" << RESET;
	if (this != &other)
	{
		Animal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << Cyan << "this is Dog wof wof\n" << RESET;
}

Dog::~Dog()
{
	delete brain;
	std::cout << Cyan << type << " Destructor\n" << RESET;
}
