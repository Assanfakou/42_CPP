#include "Zombie.hpp"

int main(void)
{
    randomChump("stack");

    Zombie *z = newZombie("z");
    z->announce();

    delete z;
}