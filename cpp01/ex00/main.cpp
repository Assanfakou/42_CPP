#include "Zombie.h"

int main(void)
{
    randomChump("assan");
    Zombie *z = newZombie("fakou");
    z->announce();
    delete z;
}