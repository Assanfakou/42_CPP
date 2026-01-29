#include <iostream>
#include "iter.h"

int main ()
{
    char arr[] = "hello how are you doing ?";

    iter(arr, strlen(arr), fa);
    std::cout << arr;
}