#include "ScaveTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string name;
    public:
        DiamondTrap();
        DiamondTrap(const std::string& name);
        DiamondTrap(const DiamondTrap& oldObj);
        DiamondTrap& operator=(const DiamondTrap& next);

        ~DiamondTrap();
};
#endif