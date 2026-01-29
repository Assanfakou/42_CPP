#include <iostream>
#include <string.h>

template <typename T>

void fa(T a)
{
    a = 97;
    // std::cout << static_cast<char>(std::toupper(a));
}

template <typename T, typename F>

void niter(T* arr, const size_t size, F f)
{
    for (size_t i = 0; i < size; i++)
    {
        f(arr[i]);
    }
}

template <typename T>

void iter(const T* arr, const size_t size, void (*func)(const T&))
{
    niter(arr, size, func);
}

template <typename T>

void iter(T* arr, const size_t size, void (*func)(T&))
{
    niter(arr, size, func);
}