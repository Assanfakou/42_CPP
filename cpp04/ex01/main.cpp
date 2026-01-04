#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	{
		std::cout << "------------------- Deep copy (Cat copy constructor) -------------------\n";

		Brain b("original");
		Cat cat1(b);
		Cat cat2(cat1);

		std::cout << "Cat1 idea:\n";
		cat1.printIdea(0);

		std::cout << "Cat2 idea:\n";
		cat2.printIdea(0);

		std::cout << "Changing Cat1 brain\n";
		Brain newBrain("changed");
		cat1 = Cat(newBrain);

		std::cout << "Cat1 idea after change:\n";
		cat1.printIdea(0);

		std::cout << "Cat2 idea (must stay original):\n";
		cat2.printIdea(0);

		std::cout << "------------------- End -------------------\n";
	}

	{
		std::cout << "------------------- Deep copy (Cat assignment) -------------------\n";

		Brain b1("first");
		Brain b2("second");

		Cat cat1(b1);
		Cat cat2(b2);

		cat2 = cat1;

		std::cout << "Cat1 idea:\n";
		cat1.printIdea(0);

		std::cout << "Cat2 idea after assignment:\n";
		cat2.printIdea(0);

		std::cout << "Changing Cat1 brain\n";
		cat1 = Cat(Brain("changed again"));

		std::cout << "Cat1 idea:\n";
		cat1.printIdea(0);

		std::cout << "Cat2 idea (must NOT change):\n";
		cat2.printIdea(0);

		std::cout << "------------------- End -------------------\n";
	}
	{
		std::cout << "------------------- Polymorphism test -------------------\n";

		const Animal *a1 = new Dog();
		const Animal *a2 = new Cat();

		a1->makeSound();
		a2->makeSound();

		delete a1;
		delete a2;

		std::cout << "------------------- End -------------------\n";
	}
}

