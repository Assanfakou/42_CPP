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

        void whoAmi();
        ~DiamondTrap();
        void attack(const std::string& target);
        int get_hit();
        int get_energy();
        int get_attack();
};
#endif
