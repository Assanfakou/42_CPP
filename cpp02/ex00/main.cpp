#include "Fixed.hpp"

void testing(const Fixed& fix)
{
	std::cout << fix.getRawBits()<< std::endl;
}

int main ()
{
	Fixed a;
	Fixed b(a);
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}

