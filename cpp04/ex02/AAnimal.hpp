#include <iostream>
# include "colors.h"

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

class AAnimal
{
	protected:
		std::string type;
	public:
		AAnimal();
		AAnimal(const std::string& type);
		AAnimal& operator=(const AAnimal& animal);
		AAnimal(const AAnimal& animal);
		const std::string& getType() const;
		virtual void makeSound() const = 0;
		virtual ~AAnimal();
};

#endif
