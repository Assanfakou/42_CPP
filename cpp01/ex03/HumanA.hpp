#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	std::string name;
	Weapon &w;
	public:
	HumanA(const std::string& name, Weapon& w);
	void attack();
};
