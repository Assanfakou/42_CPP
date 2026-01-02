#include "Animal.hpp"

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
