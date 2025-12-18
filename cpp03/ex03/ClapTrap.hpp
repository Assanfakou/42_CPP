#include <iostream>
#include "colors.h"

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP


class ClapTrap{
	protected:
		std::string name;
		int hitPoints;
		int energyPoints;
		int attackDamage;
	public:
		ClapTrap();
		ClapTrap(const std::string &Name);

		ClapTrap(const ClapTrap& oldObj);
		ClapTrap& operator=(const ClapTrap& next);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		~ClapTrap();
};

#endif
