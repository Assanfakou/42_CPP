#include "Array.h"

int main ()
{
    try
    {
        Array<int> a(3);
        Array<char> b(4);
        const Array<char> c(3);


        a[0] = 366;
        b[0] = 97;
        std::cout << a[0] << "\n";
        std::cout << b[0] << "\n";
        std::cout << b[2] << "\n";
        std::cout << c[2] << "\n";
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << "\n";
    }
}