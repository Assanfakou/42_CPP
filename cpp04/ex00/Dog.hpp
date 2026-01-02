#include "Animal.hpp"

#ifndef DOG_HPP
#define DOG_HPP 

class Dog : public Animal
{
	public:
		Dog();
		Dog(const std::string& type);
		Dog& operator=(const Dog& animal);
		Dog(const Dog& animal);
		void makeSound() const;
		~Dog();
};
#endif
