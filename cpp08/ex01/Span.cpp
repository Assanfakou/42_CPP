#include "Span.hpp"

Span::Span(void)
{
        box.reserve(1);
}
Span::Span(unsigned int n)
{
        if (n < 2)
                throw ExceptionShort();
        else
                maxSize = n;
}
Span::Span(const Span &other)
{
        this->box = other.box;
        this->maxSize = other.maxSize;
}
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

void Span::print()
{
        for (std::vector<int>::iterator it = box.begin(); it != box.end() ; it++)
                std::cout << *it << ", ";
        std::cout << "\n";
}

int Span::longestSpan()
{
        if (box.size() < 2)
                throw ExceptionShort();
       std::vector<int>::iterator min = std::min_element(box.begin(), box.end());
       std::vector<int>::iterator max = std::max_element(box.begin(), box.end());

       return (*max - *min);
}

int Span::shortestSpan()
{
        if (box.size() < 2)
                throw ExceptionShort();

        std::vector<int> tmp = box;
        int diff;

        std::sort(tmp.begin(), tmp.end());

        int shortest = *(tmp.end() - 1) - *tmp.begin();
        for (std::vector<int>::iterator i = tmp.begin(); i != tmp.end() - 1; i++)
        {
                int diff = *(i + 1) - *i;
                if (diff < shortest)
                        shortest = diff;
        }
        //print the sorted vector
        // std::cout << std::endl;
        // for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end() ; it++)
        //         std::cout << *it << ", ";
        return shortest;
}
Span::~Span()
{

}