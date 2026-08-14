
#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
class Span
{
      private:
        std::vector<int> box;
        unsigned int maxSize;

      public:
        Span(void);
        Span(unsigned int size);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int n);
        long shortestSpan();
        long longestSpan();
        class ExceptionLong : public std::exception
        {
            const char *what() const throw();
        };
        class ExceptionShort : public std::exception
        {
            const char *what() const throw();
        };

        template <typename iter>
        void addNumbers(iter begin, iter end)
        {
          unsigned int rangesize = std::distance(begin, end);

          if (box.size() + rangesize > maxSize)
            throw ExceptionLong();

          box.insert(box.end(), begin, end);
        }
};
