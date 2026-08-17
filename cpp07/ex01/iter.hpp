#pragma once

#include <iostream>

template <typename T, typename F>

void iter(T* arr, const size_t size, F f)
{
    if (!arr)
        return ;
    for (size_t i = 0; i < size; i++)
    {
        f(arr[i]);
    }
}
