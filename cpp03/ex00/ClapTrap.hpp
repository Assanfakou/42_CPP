#include <iostream>
#include "colors.h"

#ifndef ClapTrap_HPP
# define ClapTrap_HPP


class ClapTrap{
	private:
		std::string Name;
		unsigned int Hit;
		unsigned int Energy;
		unsigned int AttackDammage;
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
