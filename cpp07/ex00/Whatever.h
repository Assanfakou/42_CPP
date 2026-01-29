#include <iostream>

template <typename T>

void swap(T& x, T& y)
{
    T temp = x;
    x = y;
    y = temp;
}

template <typename T>

const T& max(const T& a, const T& b)
{
    if (a < b)
        return b;
    else if (a > b)
        return a;
    else
        return b; 
}

template <typename T>

const T& min(const T& a, const T& b)
{
    if (a < b)
        return a;
    else if (a > b)
        return b;
    else
        return b; 
}
