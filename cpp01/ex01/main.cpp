#include "Zombie.h"


int main ()
{
    Zombie *z = zombieHorde(5, "assan");
    z->announce();
    // delete z;
}