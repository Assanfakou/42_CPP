#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << Blue << type << " default constructor\n" << RESET;
}

WrongCat::WrongCat(const std::string& type) : WrongAnimal(type)
{
	std::cout << Blue << type << " default parametrized constructor\n" << RESET;
}

WrongCat::WrongCat(const WrongCat& obj) : WrongAnimal(obj)
{
	std::cout << Green << type << " copy constructor\n" << RESET;
	this->type = obj.type;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << Green << type << "copy assignement operator\n" << RESET;
	if (this != &other)
		WrongAnimal::operator=(other);
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << Yellow << "this is WrongCat Meow\n" << RESET;
}

WrongCat::~WrongCat()
{
	std::cout << RED << type << " Destructor\n " << RESET;
}
