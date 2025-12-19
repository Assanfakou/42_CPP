#include "ScaveTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << Green << "ScavTrap Default construtor called\n" << RESET;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string& _name)
{
    std::cout << Green << "ScavTrap Default Parametrized construtor called\n" << RESET;
    name = _name;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}
ScavTrap::ScavTrap(const ScavTrap& oldObj) : ClapTrap(oldObj)
{
	std::cout << Green << "ScaveTrap copy Constructor called\n" << RESET;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& next)
{
	std::cout << Green << "ScavTrap copy assignement operator called\n" << RESET;
	if (this != &next)
        ClapTrap::operator=(next);
	return *this;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->hitPoints == 0) { std::cout << Green << "ScavTrap " << this->name << " is dead\n" << RESET; return ; } if (this->energyPoints == 0)
	{
		std::cout << Green << "ScavTrap " << this->name << " is Exhausted\n" << RESET;
		return ;
	}
	this->energyPoints--;
	std::cout << Green << "ScavTrap " << this->name << " Attacks " << target << ", causing Damage : " << this->attackDamage << std::endl << RESET;	
}

void ScavTrap::guardGate(){
    std::cout << Green << "ScavTrap " << name << " is now on Gate keeper mode\n" << RESET; 
}
ScavTrap::~ScavTrap()
{
    std::cout << RED << "ScavTrap destructor called | " << this->name << "|\n" << RESET;
}
