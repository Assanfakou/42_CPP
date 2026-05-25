
#pragma once

#include <iostream>
#include <algorithm>
#include <stack>

class RPN
{
      private:
        std::stack<int> stack;
      public:
        RPN(void);
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();
};

