#ifndef SPAN
#define SPAN

#include <iostream>
#include <algorithm>
#include <vector>


class Span
{
      private:
        std::vector<int> box;
        unsigned int maxSize;
      public:
        Span(unsigned int size);
        Span(void);
        Span(const Span& other);
        Span& operator=(const Span& other);

        void addNumber(int n);
        template <typename iter>
        void addNumber(iter begin, iter end)
        {
          unsigned int rangesize = std::distance(begin, end);

          if (box.size() + rangesize > maxSize)
            throw ExceptionLong();

          box.insert(box.end(), begin, end);
        }
        int shortestSpan();
        int longestSpan();
        void print();

        class ExceptionLong : public std::exception
        {
            const char *what() const throw();
        };
        class ExceptionShort : public std::exception
        {
            const char *what() const throw();
        };

        ~Span();
};

#endif
