#include "Zombie.h"

int main ()
{
    Zombie *z = zombieHorde(5, "assan");
    for (int i = 0; i < 5; i++)
        z[i].announce();

    delete []z;
}