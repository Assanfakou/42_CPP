#include "Zombie.hpp"

int Zombie::i = 0; 

int main ()
{
    Zombie *z = zombieHorde(5, "assan");
    for (int i = 0; i < 5; i++)
        z[i].announce();
    
    delete []z;
}