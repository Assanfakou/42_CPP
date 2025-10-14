#include <iostream>

class Zombie{
    private:
        std::string name;
    public:
        Zombie(std::string name)  : name(name) {} 
        void announce(void)
        {
           std::cout << name << ": BraiiiiiiinnnzzzZ..."<< std::endl;
        }
        ~Zombie(){
           std::cout << name<< " is destroyed!!"<< std::endl;
        }
};

void randomChump(std::string name);
Zombie *newZombie(std::string name);