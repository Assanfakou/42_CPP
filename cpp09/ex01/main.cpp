#include "RPN.hpp"

int main(int ac, char *av[])
{
    if (ac != 2)
    {
        std::cerr << "Must be there is some input\n";
        return 1;
    }
    try
    {
        RPN r;
        std::cout << r.load_data(av[1]) << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error" << '\n';
        return 0;
    }
    
}