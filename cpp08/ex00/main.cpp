#include <iostream>
#include <vector>
#include <algorithm>
#include "MyExeption.hpp"

int main ()
{
    std::vector<int> v = {1, 3, 4, 4, 5, 5, 6, 4};
    try
    {
        std::vector<int>::iterator it = easyfind(v, 3); std::cout << *it;
    }

    catch (const MyExeption &e)
    {
        std::cerr << e.what() << '\n';
    }

}
