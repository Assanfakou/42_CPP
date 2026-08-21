#pragma once

#include <iostream>
#include <algorithm>
#include <stack>
#include <sstream>

class RPN
{
      private:
        std::stack<int> stack;

      public:
        RPN(void);
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();

        int load_data(const std::string &input);
};
