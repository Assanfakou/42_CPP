#include <iostream>

class Zombie{
    private:
        std::string name;
    public:
        Zombie(){} 
        void announce(void)
        {
           std::cout << name << ": BraiiiiiiinnnzzzZ..."<< std::endl;
        }
        void setName(const std::string& name)
        {
            this->name = name;
        }
        ~Zombie(){
           std::cout << name<< " is destroyed!!"<< std::endl;
        }
};

Zombie* zombieHorde(int N, std::string name);