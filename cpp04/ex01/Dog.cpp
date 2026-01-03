#include "Dog.hpp"

Dog::Dog() : Animal()
{
	type = "Dog";
	brain = new Brain();
	std::cout << Green << type << " default constructor\n" << RESET;
}

Dog::Dog(const Dog& anim) : Animal(anim)
{
	std::cout << Green << type << " copy constructor\n" << RESET;
	brain = new Brain(*anim.brain);
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << Green << type << " copy assignement operator\n" << RESET;
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
	std::cout << Green << "this is Dog wof wof\n" << RESET;
}

Dog::~Dog()
{
	delete brain;
	std::cout << Green << type << " Destructor\n" << RESET;
}
