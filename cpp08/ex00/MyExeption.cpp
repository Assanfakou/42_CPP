#include "MyExeption.hpp"

const char* MyExeption::what() const throw()
{
    return "found no value";
}