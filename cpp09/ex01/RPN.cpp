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

bool RPN::isOperator(char c)
{
        if (stack.size() < 2)
                return false;
        int b = stack.top();
        stack.pop();
        int a = stack.top();
        stack.pop();
        
        if (c == '+')
                stack.push(a + b);
        else if (c == '-')
                stack.push(a - b);
        else if (c == '*')
                stack.push(a * b);
        else if (c == '/')
                stack.push(a / b);
        return true;
}

void RPN::load_data(const std::string &input)
{
        std::string tmp = input;
        std::string::iterator it;
        
        for (it = tmp.begin(); it != tmp.end(); it++)
        {
                if (std::isdigit(*it))
                {
                        stack.push(*it - '0');
                        continue;
                }
                else if (*it == '-' || *it == '+' || *it == '/' || *it == '*')
                {
                        if (isOperator(*it))
                                continue;
                        else
                        {
                                std::cerr << "Error\n";
                                return;
                        }
                }
                else if (*it == ' ')
                        continue;
                else 
                {
                        std::cerr << "Error\n";
                        return ;
                }
        }
        if (stack.size() != 1)
        {
                std::cerr << "Error\n";
                return ;
        }
        else
                std::cout << stack.top() << "\n";
}
RPN::~RPN()
{
}
