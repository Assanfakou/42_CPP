#include "Cat.hpp"

Cat::Cat() : Animal()
{
	type = "Cat";
	b = new Brain();
	std::cout << Blue << type << " default constructor\n" << RESET;
}

Cat::Cat(const Cat& obj) : Animal(obj)
{
	std::cout << Green << type << " copy constructor\n" << RESET;
	b = new Brain(*obj.b);
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << Green << type << "copy assignement operator\n" << RESET;
	if (this != &other)
	{
		Animal::operator=(other);
		delete b;
		b = new Brain(*other.b);
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << Yellow << "this is cat Meow\n" << RESET;
}
void Cat::printIdea(int i) const
{
	b->getIdea(i);
}

void Cat::printIdeas() const
{
	b->getIdeas();
}

Cat::~Cat()
{
	delete b;
	std::cout << RED << type << " Destructor\n" << RESET;
}
