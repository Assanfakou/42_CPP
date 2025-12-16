#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << Cyan << "Default constructor called\n"; 
}

ClapTrap::ClapTrap(const std::string& name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << Cyan << "Default Parameterized constructor called\n"; 
}

ClapTrap::ClapTrap(const ClapTrap& oldObj)
{
	std::cout << Blue << "copy Constructor called\n" << RESET;
	*this = oldObj;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& next)
{
	std::cout << Green << "copy assignement operator called\n" << RESET;
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
		std::cout << RED << "ClapTrap " << this->name << " is dead\n" ;
		return ;
	}
	if (this->energyPoints == 0)
	{
		std::cout << RED << "ClapTrap " << this->name << " is Exhausted\n" ;
		return ;
	}
	this->energyPoints--;
	std::cout << "ClapTrap " << this->name << " Attacks " << target << ", causing Damage : " << this->attackDamage << std::endl;	
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints == 0)
	{
		std::cout << RED << "ClapTrap " << this->name << " is dead\n" ;
		return ;
	}
	if (this->energyPoints == 0)
	{
		std::cout << RED << "ClapTrap " << this->name << " is Exhausted\n" ;
		return ;
	}
	this->energyPoints--;	
	hitPoints += amount;
	std::cout << "ClapTrap " << this->name << " Got Repaired hit points reached  : " << this->hitPoints << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    this->hitPoints -= amount;
    if (this->hitPoints < 0)
        this->hitPoints = 0;
    
    std::cout << "ClapTrap "<< name << " took " << amount<<  " damage, hitPoints is reached " << hitPoints << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << RED << "destructur called | " << this->name << " |\n" << RESET;
}
