#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>

typename T::iterator easyfind(T& continer, int value)
{
    auto it = std::find(continer.begin(), continer.end(), value);

    return it;
}

int main ()
{
    std::vector<int> v = {1, 3, 4, 4, 5, 5, 6, 4};

    auto it = easyfind(v, 10);

    std::cout << *it++;
}
