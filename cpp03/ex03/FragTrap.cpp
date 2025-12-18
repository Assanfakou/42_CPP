#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << Green << "FragTrap Default construtor called\n" << RESET;
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
}

FragTrap::FragTrap(const std::string& _name) : ClapTrap(_name)
{
    std::cout << Green << "FragTrap Default Parametrized construtor called\n" << RESET;
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
}
FragTrap::FragTrap(const FragTrap& oldObj) : ClapTrap(oldObj)
{
	std::cout << Green << "FragTrap copy Constructor called\n" << RESET;
}

FragTrap& FragTrap::operator=(const FragTrap& next)
{
	std::cout << Green << "FragTrap copy assignement operator called\n" << RESET;
	if (this != &next)
	{
        ClapTrap::operator=(next);
		return *this;
	}
	return *this;
}

void FragTrap::highFiveGuys(){
    std::cout << Green << "FragTrap " << name << " Says Hi\n" << RESET; 
}

FragTrap::~FragTrap()
{
    std::cout << RED << "FragTrap destructor called | " << this->name << "|\n" << RESET;
}