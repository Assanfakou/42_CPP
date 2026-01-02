#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main ()
{
	{
		const Animal *meta = new Animal();
		const Animal *j = new Dog();
		const Animal *i = new Cat();

		std::cout << "--------------------Expected Output here ----------------------\n";

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); // will output the cat sound!
		j->makeSound();
		meta->makeSound();

		std::cout << "--------------------Destructors calls ----------------------\n";
		delete meta;
		delete i;
		delete j;
	}
	{
		std::cout << "--------------------Wrong output here ----------------------\n";
		const WrongAnimal *wrongA = new WrongAnimal();
		const WrongAnimal *wrongB = new WrongCat();
		wrongA->makeSound();
		wrongB->makeSound();
		std::cout << "--------------------Destructors calls ----------------------\n";
		delete wrongA;
		delete wrongB;
	}
}
