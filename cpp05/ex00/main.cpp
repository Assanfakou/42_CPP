#include <iostream>

int main () {
	
	try
	{
		int value;

		std::cin >> value;
		if (value == 10)
			throw value_is_big("big value");
		else
			std::cout << "fine value\n";
	}
	catch (exeptiion e)
	{
		std::cout << "Excetion Caught " << e.what() << std::endl;
	}
	return 0;
}
