#pragma once

#include <iostream>
#include <algorithm>
#include <stack>

class RPN
{
      private:
        std::stack<int> stack;
        bool isNumber(char c);
        bool isOperator(char c);
      public:
        RPN(void);
        void load_data(const std::string &input);
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();
};
