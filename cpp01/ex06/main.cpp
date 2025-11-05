#include <iostream>

#define Black "\033[0;30m"        // Black
#define Redr "\033[0;31m"         // Red
#define Green "\033[0;32m"        // Green
#define Yellow "\033[0;33m"       // Yellow
#define Blue "\033[0;34m"         // Blue
#define Purple "\033[0;35m"       // Purple
#define Cyan "\033[0;36m"         // Cyan
#define White "\033[0;37m"        // White

class Harl
{
	private:
	void debug();
	void info();
	void warning();
	void error();
	public:
	void complain(std::string level);
};

void Harl::debug()
{
	std::cout << Yellow << "[DEBUG]\n" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
	std::cout << Green << "[INFO]\n" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning()
{
	std::cout << Purple << "[WARNING]\n" << std::endl;
	std::cout << "think I deserve to have some extra bacon for free. I’ve been coming foryears whereas you started working here since last month." << std::endl;
}
void Harl::error()
{
	std::cout << Redr << "[ERROR]\n" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
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
		case (1):
			(this->*functions[1])();
		case (2):
			(this->*functions[2])();
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
