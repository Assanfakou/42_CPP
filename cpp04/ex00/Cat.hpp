#include "Animal.hpp"

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
