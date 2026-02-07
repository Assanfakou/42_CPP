#ifndef SCALAR_CONVERTER
#define SCALAR_CONVERTER

#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <cmath>
#include <iomanip> 

class ScalarConverter
{
      private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();
      public:
        static void convert(const std::string& inp);
};

#endif
