#include "Harl.hpp"

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
	std::cout << Blue << "[WARNING]\n" << std::endl;
	std::cout << "think I deserve to have some extra bacon for free. I’ve been coming foryears whereas you started working here since last month." << std::endl;
}
void Harl::error()
{
	std::cout << Redr << "[ERROR]\n" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}