#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), name("default")
{
	std::cout << Yellow << "DiamondTrap Default construtor called\n" << RESET;
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = 50;
	this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(const std::string& _name) : ClapTrap(_name + "_clap_name"), name(_name)
{
	std::cout << Yellow << "DiamondTrap Default Parametrized construtor called\n" << RESET;
	hitPoints = FragTrap::hitPoints;
	energyPoints = 50;
	attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& oldObj)
{
	*this = oldObj;
	std::cout << Yellow << "DiamondTrap copy Constructor called\n" << RESET;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& next)
{
	std::cout << Yellow << "DiamondTrap copy assignement operator called\n" << RESET;
	if (this != &next)
	{
		this->name = next.name;
		ClapTrap::operator=(next);
		hitPoints = next.hitPoints;
		energyPoints = next.energyPoints;
		attackDamage = next.attackDamage;
	}
	return *this;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmi()
{
	std::cout << Yellow << "I am " << DiamondTrap::name << " but you can call me " << ClapTrap::name << "\n" << RESET;
}

int DiamondTrap::get_hit()
{
	return this->hitPoints;
}

int DiamondTrap::get_energy()
{
	return ScavTrap::energyPoints;
}
int DiamondTrap::get_attack()
{
	return this->attackDamage;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << RED << "DiamondTrap destructor called | " << this->name << "|\n" << RESET;
}