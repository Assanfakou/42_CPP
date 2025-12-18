#include "ScaveTrap.hpp"


int main()
{
	std::cout << "----- ORIGINAL -----" << std::endl;
    ScavTrap a("Alpha");
    a.attack("enemy");

    std::cout << "\n----- COPY CONSTRUCTOR -----" << std::endl;
    ScavTrap b(a);
    b.attack("enemy");

    std::cout << "\n----- COPY ASSIGNMENT -----" << std::endl;
    ScavTrap c("Temp");
    c = a;
    c.attack("enemy");

    return 0;
    // std::cout << "----- BASIC CONSTRUCTION TEST -----" << std::endl;
    // {
    //     ScavTrap a("Alpha");
    // }

    // std::cout << "\n----- ATTACK & ENERGY TEST -----" << std::endl;
    // ScavTrap b("Bravo");
    // for (int i = 0; i < 52; i++)
    //     b.attack("Target");

    // std::cout << "\n----- DAMAGE & DEAD STATE TEST -----" << std::endl;
    // ScavTrap c("Charlie");
    // c.takeDamage(150);
    // c.attack("Target");
    // c.beRepaired(10);

    // std::cout << "\n----- GUARD GATE TEST -----" << std::endl;
    // ScavTrap d("Delta");
    // d.guardGate();

    // std::cout << "\n----- POLYMORPHISM TEST -----" << std::endl;
    // ClapTrap* ptr = new ScavTrap("Echo");
    // ptr->attack("Target");
    // delete ptr;

    // return 0;

    // ScavTrap a("White");
    // a.attack("Dark");
    // // a.takeDamage(30);
    // // a.beRepaired(5);
    // // a.guardGate();

    // // ScavTrap b("blue");
    // // b.attack("Green");
    // // b.guardGate();

    // // ScavTrap c(a);
    // // c.attack("skiny");
    // // c.takeDamage(200);
    // // c.beRepaired(100);
    // // c.guardGate();

    // // ScavTrap d;
    // // d = b;
    // // d.attack("fat");
    // // d.takeDamage(30);
    // // d.beRepaired(30);
    // // d.guardGate();
}