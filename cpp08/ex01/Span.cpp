#include "Span.hpp"

Span::Span(void) : maxSize(0) {}

Span::Span(unsigned int n) : maxSize(n) {}

Span::Span(const Span &other) : box(other.box), maxSize(other.maxSize) {}

Span &Span::operator=(const Span &other)
{
        if (this != &other)
        {
                this->box = other.box;
                this->maxSize = other.maxSize;
        }
        return *this;
}

void Span::addNumber(int n)
{
        if (box.size() == maxSize)
                throw ExceptionLong();
        box.push_back(n);
}

const char *Span::ExceptionLong::what() const throw()
{
        return "Reached The Max Size";
}

const char *Span::ExceptionShort::what() const throw()
{
        return "The Size Should Be More Than Two";
}

long Span::longestSpan()
{
        if (box.size() < 2)
                throw ExceptionShort();
        long min = *std::min_element(box.begin(), box.end());
        long max = *std::max_element(box.begin(), box.end());

       return std::abs(max - min);
}

long Span::shortestSpan()
{
        if (box.size() < 2)
                throw ExceptionShort();

        std::vector<int> tmp = box;

        std::sort(tmp.begin(), tmp.end());

        long tobeshortest = static_cast<long>(*(tmp.end() - 1)) - static_cast<long>(*tmp.begin());
        for (std::vector<int>::iterator i = tmp.begin(); i != tmp.end() - 1; i++)
        {
                long diff = static_cast<long>(*(i + 1)) - static_cast<long>(*i);
                if (diff < tobeshortest)
                        tobeshortest = diff;
        }
        //print the sorted vector
        // std::cout << std::endl;
        // for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end() ; it++)
        //         std::cout << *it << ", ";
        return tobeshortest;
}
Span::~Span()
{
}
