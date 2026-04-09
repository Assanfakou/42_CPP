#include <iostream>
#include <vector>
#include <algorithm>
#include "MyExeption.hpp"

template <typename T>

typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);

    if (it == container.end())
        throw MyExeption();
    return it;
}

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
