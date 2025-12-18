#include "ClapTrap.hpp"

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP


class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(const std::string& name);
        ScavTrap& operator=(const ScavTrap& next);
        ScavTrap(const ScavTrap& oldObj);
        ~ScavTrap();

        void attack(const std::string& target);
        void guardGate();
};

#endif