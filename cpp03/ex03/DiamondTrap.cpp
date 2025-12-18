#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : FragTrap()
{
    std::cout << Green << "DiamondTrap Default construtor called\n" << RESET;
    this->name = "default";
    hitPoints = FragTrap::hitPoints;
    energyPoints = ScavTrap::energyPoints;
    attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(const std::string& _name) : FragTrap(_name + "_clap_name")
{
    std::cout << Green << "DiamondTrap Default Parametrized construtor called\n" << RESET;
    this->name = _name;
    hitPoints = FragTrap::hitPoints;
    energyPoints = ScavTrap::energyPoints;
    attackDamage = FragTrap::attackDamage;
}
DiamondTrap::DiamondTrap(const DiamondTrap& oldObj) : ClapTrap(oldObj)
{
	std::cout << Green << "DiamondTrap copy Constructor called\n" << RESET;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& next)
{
	std::cout << Green << "DiamondTrap copy assignement operator called\n" << RESET;
	if (this != &next)
	{
        ClapTrap::operator=(next);
		return *this;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << RED << "DiamondTrap destructor called | " << this->name << "|\n" << RESET;
}