#ifndef SCALAR_CONVERTER
#define SCALAR_CONVERTER

#include <iostream>

class ScalarConverter
{
      public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();
        static void convert(const std::string& inp);
};

#endif
