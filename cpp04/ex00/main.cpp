#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void func(const Animal& animal)
{
	animal.makeSound();
}

int main()
{
	{
		const Animal *meta = new Animal();
		const Animal *j = new Dog();
		const Animal *i = new Cat();

		std::cout << "--------------------Expected Output here ----------------------\n";

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); // will output the cat sound
		j->makeSound(); // this will output Dogs sound
		meta->makeSound(); // meta or Animal has no sound

		std::cout << "--------------------Destructors calls ----------------------\n";
		delete meta;
		delete i;
		delete j;
	}
	{
		std::cout << "--------------------let's do somting awesome here----------------------\n";
		Animal *beta = new Animal;
		Cat *A = new Cat;
		func(*beta);
		func(*A);
		std::cout << "--------------------Destructors calls ----------------------\n";
		delete A;
		delete beta;
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
