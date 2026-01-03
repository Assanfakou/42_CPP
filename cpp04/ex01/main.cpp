#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
	{
		std::cout << "-------------------buggy assignement tests--------------------\n";
		Cat va = Cat();
		Cat ca;
		Dog ad;
		Dog copy(ad);

		ca = va;
		ca.printIdea(1);

		std::cout << "-------------------destructors begin fin--------------------\n";
	}

	{
		std::cout << "-------------------Normall output--------------------\n";
		const Animal *a = new Dog();
		const Animal *b = new Cat();
		Cat *ca = new Cat();
		ca->printIdeas();

		a->makeSound();
		b->makeSound();

		std::cout << "-------------------Destructors--------------------\n";
		delete ca;
		delete a;
		delete b;
	}
}
