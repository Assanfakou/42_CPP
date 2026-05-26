#pragma once

#include <iostream>
#include <algorithm>
#include <stack>
#include <sstream>

class RPN
{
      private:
        std::stack<int> stack;
        bool isNumber(const std::string &token);
        bool isOperator(const std::string &token);
        bool doOperator(const std::string &token);
      public:
        RPN(void);
        void load_data(const std::string &input);
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();
};
