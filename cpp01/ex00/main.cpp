#include "Zombie.h"


int main ()
{
    randomChump("assan");
    Zombie *z = newZombie("fakou");
    z->announce();
    delete z;
}