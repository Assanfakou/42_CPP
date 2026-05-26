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
bool RPN::isOperator(const std::string &token)
{
        if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] || token[0] == '/')
                return true;
        return false;
}

bool RPN::doOperator(const std::string &token)
{
        if (stack.size() < 2)
                return false;
        int b = stack.top();
        stack.pop();
        int a = stack.top();
        stack.pop();
        
        if (token[0] == '+')
                stack.push(a + b);
        else if (token[0] == '-')
                stack.push(a - b);
        else if (token[0] == '*')
                stack.push(a * b);
        else if (token[0] == '/')
                stack.push(a / b);
        return true;
}
bool RPN::isNumber(const std::string &token) 
{
        if (std::isdigit(token[0]))
                return true;
        else
                return false;
}

void RPN::load_data(const std::string &input)
{
        std::string tmp;
        std::istringstream splited(input);
        while (splited >> tmp) 
        {
                if (tmp.size() > 1)
                {
                        std::cerr << "Error\n";
                        return ;
                }
                if (isNumber(tmp))
                        stack.push(std::atoi(tmp.c_str()));
                else if (isOperator(tmp))
                        doOperator(tmp);
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
