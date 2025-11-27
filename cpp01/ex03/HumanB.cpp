#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : name(name) {}

void HumanB::setWeapon(Weapon& w)
{
    this->w = &w;
}

void HumanB::attack()
{
    std::cout << name << " attack with their " << w->getType() << std::endl;
}