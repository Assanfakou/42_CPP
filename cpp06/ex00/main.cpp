#include <iostream>
#include "ScalarConverter.h"

int main(int ac, char **av)
{
  if (ac != 2)
  {
    std::cout << "bad input\n";
    return 1;
  }
  ScalarConverter::convert(av[1]);
}
