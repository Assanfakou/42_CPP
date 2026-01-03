#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
	{
		std::cout << "-------------------Normall output--------------------\n";
		const Animal *a = new Dog();
		const Animal *b = new Cat();
		Cat *ca = new Cat();
		ca->printIdeas();
		
		a->makeSound();
		b->makeSound();

		std::cout << "-------------------Destructors--------------------\n";
		delete a;
		delete b;
	}

	{
		std::cout << "-------------------Normall output--------------------\n";
		const Animal *j = new Dog();
		const Animal *i = new Cat();

		j->makeSound();
		i->makeSound();

		std::cout << "-------------------Destructors--------------------\n";
		delete i;
		delete j;
	}
}
