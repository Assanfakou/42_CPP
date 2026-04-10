#include "easyfind.hpp"
#include <list>

int main()
{
    std::cout << "=== Test 1: vector (found) ===" << std::endl;
    try
    {
        std::vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);

        std::vector<int>::iterator it = easyfind(v, 2);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Value not found" << std::endl;
    }

    std::cout << std::endl;

    std::cout << "=== Test 2: vector (not found) ===" << std::endl;
    try
    {
        std::vector<int> v;
        v.push_back(10);
        v.push_back(20);
        v.push_back(30);

        std::vector<int>::iterator it = easyfind(v, 5);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Value not found" << std::endl;
    }

    std::cout << std::endl;

    std::cout << "=== Test 3: list (found) ===" << std::endl;
    try
    {
        std::list<int> l;
        l.push_back(7);
        l.push_back(8);
        l.push_back(9);

        std::list<int>::iterator it = easyfind(l, 8);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Value not found" << std::endl;
    }

    std::cout << std::endl;

    std::cout << "=== Test 4: list (not found) ===" << std::endl;
    try
    {
        std::list<int> l;
        l.push_back(100);
        l.push_back(200);

        std::list<int>::iterator it = easyfind(l, 42);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Value not found" << std::endl;
    }

    std::cout << std::endl;

    std::cout << "=== Test 5: duplicates ===" << std::endl;
    try
    {
        std::vector<int> v;
        v.push_back(4);
        v.push_back(4);
        v.push_back(4);

        std::vector<int>::iterator it = easyfind(v, 4);
        std::cout << "Found first occurrence: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Value not found" << std::endl;
    }

    std::cout << std::endl;

    std::cout << "=== Test 6: single element ===" << std::endl;
    try
    {
        std::vector<int> v;
        v.push_back(99);

        std::vector<int>::iterator it = easyfind(v, 99);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Value not found" << std::endl;
    }

    return 0;
}