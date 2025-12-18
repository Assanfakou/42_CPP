#include "ClapTrap.hpp"

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP


class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap(const std::string& name);
        FragTrap& operator=(const FragTrap& next);
        FragTrap(const FragTrap& oldObj);
        ~FragTrap();

        void highFiveGuys(void);
};

#endif