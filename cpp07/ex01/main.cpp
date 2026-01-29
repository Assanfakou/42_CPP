#include <iostream>
#include "iter.h"

int main ()
{
    int arr[] = {1, 2, 3, 4, 5, 6};

    iter(arr, sizeof(arr) / 4, fa);

    for (int i = 0; i < static_cast<int>(sizeof(arr) / 4); i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";

     char stri[] = "hello friend this is the end of your life";

    iter(stri, strlen(stri), fa);
    std::cout << stri;
}