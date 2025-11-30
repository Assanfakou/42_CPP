#include "Fixed.hpp"

void testing(const Fixed& fix)
{
	std::cout << fix.getRawBits()<< std::endl;
}

int main ()
{
	Fixed a;
	Fixed  b(10);
	Fixed  c(10);
	Fixed const d(b);

	if (b != c)
		std::cout << "equals" << std::endl;
	else
		std::cout << "doesn't" << std::endl;
		
	return 0;
}

