#include "Animal.hpp"

#ifndef CAT_HPP
#define CAT_HPP 

class Cat : public Animal
{
	public:
		Cat();
		Cat(const std::string& type);
		Cat& operator=(const Cat& animal);
		Cat(const Cat& animal);
		void makeSound() const;
		~Cat();
};
#endif
