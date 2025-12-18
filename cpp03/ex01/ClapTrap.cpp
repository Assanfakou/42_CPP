#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << Blue << "ClapTrap Default constructor called\n" << RESET; 
}

ClapTrap::ClapTrap(const std::string& name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << Blue << "ClapTrap Default Parameterized constructor called\n" << RESET; 
}

ClapTrap::ClapTrap(const ClapTrap& oldObj)
{
	std::cout << Blue << "ClapTrap copy Constructor called\n" << RESET;
	*this = oldObj;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& next)
{
	std::cout << Blue << "ClapTrap copy assignement operator called\n" << RESET;
	if (this != &next)
	{
		this->name = next.name;
		this->energyPoints = next.energyPoints;
		this->hitPoints = next.hitPoints;
		this->attackDamage = next.attackDamage;
		return *this;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->hitPoints == 0)
	{
		std::cout << RED << "ClapTrap " << this->name << " is dead\n" << RESET;
		return ;
	}
	if (this->energyPoints == 0)
	{
		std::cout << RED << "ClapTrap " << this->name << " is Exhausted\n" << RESET;
		return ;
	}
	this->energyPoints--;
	std::cout << Blue << "ClapTrap " << this->name << " Attacks " << target << ", causing Damage : " << this->attackDamage << std::endl << RESET;	
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints == 0)
	{
		std::cout << RED << "ClapTrap " << this->name << " is dead\n" << RESET;
		return ;
	}
	if (this->energyPoints == 0)
	{
		std::cout << RED << "ClapTrap " << this->name << " is Exhausted\n" << RESET;
		return ;
	}
	this->energyPoints--;	
	hitPoints += amount;
	std::cout << Blue << "ClapTrap " << this->name << " Got Repaired hit points reached  : " << this->hitPoints << std::endl << RESET;
}
void ClapTrap::takeDamage(unsigned int amount)
{
  	this->hitPoints -= amount;
    if (this->hitPoints < 0)
        this->hitPoints = 0;

    std::cout << Blue << "ClapTrap "<< name << " took " << amount<<  " damage, hitPoints is reached " << hitPoints << std::endl << RESET;
}

ClapTrap::~ClapTrap()
{
	std::cout << RED << "ClapTrap destructur called | " << this->name << " |\n" << RESET;
}
