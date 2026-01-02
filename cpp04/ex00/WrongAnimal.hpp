#include <iostream>
#include "colors.h"

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(const std::string& type);
		WrongAnimal& operator=(const WrongAnimal& animal);
		WrongAnimal(const WrongAnimal& animal);
		const std::string& getType() const;
		void makeSound() const;
	   	~WrongAnimal();
};

#endif