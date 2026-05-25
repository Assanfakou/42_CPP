#include "RPN.hpp"

int main(int ac, char *av[])
{
    if (ac < 2)
    {
        std::cerr << "Must be there is some input\n";
        return 1;
    }

    RPN r;
    r.load_data(av[1]);
}