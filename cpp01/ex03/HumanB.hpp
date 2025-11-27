#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	Weapon *w;
	std::string name;
	public:
	HumanB(const std::string& name);
	void setWeapon(Weapon& w);
	void attack();
};
