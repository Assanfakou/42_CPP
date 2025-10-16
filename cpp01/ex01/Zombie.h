#include <iostream>

class Zombie{
    private:
    static int i;
    std::string name;
    public:
    Zombie() {} 
    void announce(void)
    {
        std::cout << name << " Number : " << i++ << ": BraiiiiiiinnnzzzZ..."<< std::endl;
    }
    void setName(const std::string& name)
    {
        this->name = name;
    }
    ~Zombie(){
        std::cout << name << " " << --i << " is destroyed!!"<< std::endl;
    }
};

Zombie* zombieHorde(int N, std::string name);