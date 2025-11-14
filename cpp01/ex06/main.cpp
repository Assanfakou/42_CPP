#include "Harl.hpp"

int get_index(std::string level)
{
	std::string level1[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (level == level1[i])
			return i;
	}
	return -1;
}
		
void Harl::complain(std::string level)
{
	void (Harl::*functions[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	
	switch (get_index(level))
	{
		case (0):
			(this->*functions[0])();
			// fall through
		case (1):
			(this->*functions[1])();
			// fall through
		case (2):
			(this->*functions[2])();
			// fall through
		case (3):
			(this->*functions[3])();
			break;
		default:
			std::cout << Redr << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
	return ;
}

int main(int ac, char **av)
{
	Harl h;
	
	if (ac < 2 || ac > 2)
		return 1;
	h.complain(av[1]);
}
