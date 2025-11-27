#include "Zombie.hpp"

Zombie::Zombie(){} 

void Zombie::announce(void)
{
    std::cout << name << " Number : " << i++ << ": BraiiiiiiinnnzzzZ..."<< std::endl;
}

void Zombie::setName(const std::string& name)
{
    this->name = name;
}

Zombie::~Zombie(){
    std::cout << name << " " << --i << " is destroyed!!"<< std::endl;
}