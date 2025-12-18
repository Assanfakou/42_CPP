#include "FragTrap.hpp"

int main()
{
    FragTrap alpha("Alpha");
    FragTrap beta("Beta");
    FragTrap gamma("Gamma");

    alpha.highFiveGuys();
    beta.highFiveGuys();
    gamma.highFiveGuys();

    FragTrap delta;
    FragTrap epsilon;
    delta = epsilon = alpha;
    delta.highFiveGuys();
    epsilon.highFiveGuys();

    FragTrap zeta(FragTrap("ZetaTemp"));
    zeta.highFiveGuys();

    alpha.attack("Enemy1");
    beta.attack("Enemy2");
    gamma.attack("Enemy3");

    alpha.highFiveGuys();
    beta.highFiveGuys();
    gamma.highFiveGuys();
}
