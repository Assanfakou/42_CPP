
#pragma once

#include <iostream>


class MyExeption :public std::exception
{
    public:
        const char *what() const throw();
};

template <typename T>

typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);

    if (it == container.end())
        throw MyExeption();
    return it;
}