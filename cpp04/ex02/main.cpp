#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	{
		std::cout << "------------------- Polymorphism test -------------------\n";

		const AAnimal *a1 = new Dog();
		const AAnimal *a2 = new Cat();
		// const AAnimal *aw = new AAnimal();
		a1->makeSound();
		a2->makeSound();

		delete a1;
		delete a2;

		std::cout << "------------------- End -------------------\n";
	}
}

