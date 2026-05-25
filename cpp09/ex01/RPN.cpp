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

void RPN::load_data(const std::string &input)
{
        std::string tmp = input;
        std::string::iterator it = tmp.begin();
        
        for (it; it != tmp.end(); ++it)
        {
                if (std::isdigit(tmp.at(it)))
                {
                        stack.push(std::atoi(tmp.at(it)));
                        continue;
                }
                else if (tmp.at(it) == '-' || '+' || '/' || '*')
                        // handle operator
                else if (tmp.at(it) == ' ')
                        continue;
                else 
                {
                        std::cerr << "Error\n";
                        return ;
                }
        }
}
RPN::~RPN()
{
}
