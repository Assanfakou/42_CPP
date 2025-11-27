#include <iostream>

class Zombie{
    private:
    static int i;
    std::string name;
    public:
    Zombie(); 
    void announce(void);
    void setName(const std::string& name);
    ~Zombie();
};

Zombie* zombieHorde(int N, std::string name);