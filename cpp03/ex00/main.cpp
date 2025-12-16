#include "ClapTrap.hpp"

int main ()
{
	ClapTrap a("assan");
	a.attack("Target");
	a.takeDamage(10);
	a.beRepaired(3);

	ClapTrap b;

	b.attack("bratan");
	b.takeDamage(5);
	b.beRepaired(10);
}

