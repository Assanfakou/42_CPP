#include <iostream>
#include <vector>
#include "Span.hpp"

int main()
{
    // ===== BASIC TEST =====
    std::cout << "=== Basic test ===" << std::endl;
    try
    {
        Span sp(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught in basic test" << e.what() << std::endl;
    }

    std::cout << std::endl;

    // ===== OVERFLOW TEST =====
    std::cout << "=== Overflow test ===" << std::endl;
    try
    {
        Span sp(3);

        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        sp.addNumber(4); // should throw
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught (overflow) " << e.what() << std::endl;
    }

    std::cout << std::endl;

    // ===== NOT ENOUGH NUMBERS TEST =====
    std::cout << "=== Not enough numbers test ===" << std::endl;
    try
    {
        Span sp(5);

        sp.addNumber(42);

        std::cout << sp.shortestSpan() << std::endl; // should throw
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught (not enough numbers)" << e.what() << std::endl;
    }

    std::cout << std::endl;

    // ===== RANGE INSERT TEST =====
    std::cout << "=== Range insert test ===" << std::endl;
    try
    {
        Span sp(10);
        std::vector<int> v;

        for (int i = 0; i < 5; i++)
            v.push_back(i * 10);

        sp.addNumber(v.begin(), v.end());

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught in range test" << std::endl;
    }

    std::cout << std::endl;

    // ===== 10,000 NUMBERS TEST =====
    std::cout << "=== 10,000 numbers test ===" << std::endl;
    try
    {
        Span sp(10000);
        std::vector<int> big;

        for (int i = 0; i < 10000; i++)
            big.push_back(i);

        sp.addNumber(big.begin(), big.end());

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught in big test" << std::endl;
    }

    std::cout << std::endl;

    // ===== RANDOM ORDER TEST =====
    std::cout << "=== Random order test ===" << std::endl;
    try
    {
        Span sp(6);

        sp.addNumber(100);
        sp.addNumber(3);
        sp.addNumber(50);
        sp.addNumber(51);
        sp.addNumber(2);
        sp.addNumber(200);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught in random test" << std::endl;
    }

    return 0;
}