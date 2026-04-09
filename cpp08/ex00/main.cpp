#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>

typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);

    if (it == container.end())
        throw std::exception();
    return it;
}

int main ()
{
    std::vector<int> v = {1, 3, 4, 4, 5, 5, 6, 4};
    try
    {
        auto it = easyfind(v, 4);
        std::cout << *it;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

}
