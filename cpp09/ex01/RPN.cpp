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

int RPN::load_data(const std::string &input)
{
    std::stringstream ss(input);
    std::string token;

    while (ss >> token)
    {
        if (token.length() == 1 && std::isdigit(token[0]))
            stack.push(token[0] - '0');
        else if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (stack.size() < 2)
                    throw std::exception();

            int b = stack.top();
            stack.pop();

            int a = stack.top();
            stack.pop();

            if (token == "+")
                stack.push(a + b);
            else if (token == "-")
                stack.push(a - b);
            else if (token == "*")
                stack.push(a * b);
            else
            {
                if (b == 0)
                        throw std::exception();
                stack.push(a / b);
            }
        }
        else
                throw std::exception();
    }

    if (stack.size() != 1)
            throw std::exception();
    
    return stack.top();
}