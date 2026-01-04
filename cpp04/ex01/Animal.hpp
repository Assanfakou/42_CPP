#include <iostream>
# include "colors.h"

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const std::string& type);
		Animal& operator=(const Animal& animal);
		Animal(const Animal& animal);
		const std::string& getType() const;
		virtual void makeSound() const;
		virtual ~Animal();
};

#endif
