
#pragma once

#include <iostream>

class MyExeption :public std::exception
{
    public:
        const char *what() const throw();
};