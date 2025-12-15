#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : Name("Default"), Hit(10), Energy(10), AttackDammage(0) {
	std::cout << Cyan << "Default constructor called\n"; 
}

ClapTrap::ClapTrap(const std::string& name) : Name(name), Hit(10), Energy(10), AttackDammage(0){
	std::cout << Cyan << "Default Parametre constructor called\n"; 
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
		this->Name = next.Name;
		this->Energy = next.Energy;
		this->Hit = next.Hit;
		this->AttackDammage = next.AttackDammage;
		return *this;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->Hit == 0)
	{
		std::cout << RED << "ClapTrap " << this->Name << " is dead\n" ;
		return ;
	}
	if (this->Energy == 0)
	{
		std::cout << RED << "ClapTrap " << this->Name << " is Exhausted\n" ;
		return ;
	}
	this->Energy--;
	std::cout << "ClapTrap " << this->Name << " Attacks " << target << ", causing AttackDammage : " << this->AttackDammage << std::endl;	
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->Hit == 0)
	{
		std::cout << RED << "ClapTrap " << this->Name << " is dead\n" ;
		return ;
	}
	if (this->Energy == 0)
	{
		std::cout << RED << "ClapTrap " << this->Name << " is Exhausted\n" ;
		return ;
	}
	this->Energy--;	
	std::cout << "ClapTrap " << this->Name << " Got Repaired with: " << amount << std::endl;
	Hit += amount;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->Hit == 0)
	{
		std::cout << RED << "ClapTrap " << this->Name << " is already out of hit points and cannot take damage.\n" ;
		return ;
	}
	if (this->Hit <= amount)
	{
		std::cout << "ClapTrap " << this->Name << " is hit for " << amount << " points of damage and is destroyed! Hit points: 0." << std::endl;
		this->Hit = 0;
	}
	else
	{
		this->Hit -= amount;
		std::cout << "ClapTrap " << this->Name << " is hit for " << amount << " points of damage! It now has " << this->Hit << " hit points remaining." << std::endl;
	}	
}	
ClapTrap::~ClapTrap()
{
	std::cout << RED << "destructur called\n" << RESET;
}
