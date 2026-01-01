#include <iostream>
#include "colors.h"

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const std::string& type);
		Animal& operator=(const Animal& animal);
		Animal(const Animal& animal);
		void makeSound();
		~Animal();
};
