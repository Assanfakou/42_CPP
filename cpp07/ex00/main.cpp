#include "Whatever.hpp"

int main ()
{
    int a = 2;
    int b = 19;

    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << "\n";
    std::cout << "min(a, b) = " << ::min(a, b) << "\n";
    std::cout << "max(a, b) = " << ::max(a, b) << "\n";

    std::string c = "good";
    std::string d = "bad";

    ::swap(c, d);
    std::cout << "\nc = " << c << ", d = " << d << "\n";
    std::cout << "min(c, d) = " << ::min(c, d) << "\n";
    std::cout << "max(c, d) = " << ::max(c, d) << "\n";
}
