#include "RPN.hpp"

RPN::RPN(void)
{
}

RPN::RPN(const RPN &other)
{
        *this = other;
}

RPN &RPN::operator=(const RPN &other)
{
        if (this != &other)
        {
                stack = other.stack;
        }
        return (*this);
}

RPN::~RPN()
{
}
