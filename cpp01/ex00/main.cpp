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
};


int main ()
{
    Zombie z("assan");
    z.announce();

}