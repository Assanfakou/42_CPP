#include "Animal.hpp"
#include "Brain.hpp"

#ifndef DOG_HPP
#define DOG_HPP 

class Dog : public Animal
{
	private:
		Brain *brain;
	public:
		Dog();
		Dog& operator=(const Dog& animal);
		Dog(const Dog& animal);
		void makeSound() const;
		~Dog();
};

#endif
