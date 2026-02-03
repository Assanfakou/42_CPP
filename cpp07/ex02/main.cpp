#include "Array.h"

int main ()
{
    try
    {
        Array<int> a(3);
        Array<char> b(4);

        a[0] = 366;
        b[0] = 97;
        std::cout << a[0] << "\n";
        std::cout << b[0] << "\n";
        std::cout << b[6] << "\n";
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << "\n";
    }
}