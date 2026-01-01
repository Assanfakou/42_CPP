#include "Animal.hpp"

class Cat : public Animal
{
	protected:
		std::string type;
	public:
		Cat();
		Cat(const std::string& type);
		Cat& operator=(const Cat& animal);
		Cat(const Cat& animal);
		void makeSound();
		~Cat();
};
