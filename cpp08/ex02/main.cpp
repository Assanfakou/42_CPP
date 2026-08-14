#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
    std::cout << "============================" << std::endl;
    std::cout << "TEST 1: MutantStack" << std::endl;
    std::cout << "============================" << std::endl;

    MutantStack<int> mstack;

    mstack.push(10);
    mstack.push(20);
    mstack.push(30);
    mstack.push(40);

    std::cout << "Top (stack behavior): " << mstack.top() << std::endl;

    std::cout << "Iteration (container behavior):" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << std::endl;


    std::cout << "\n============================" << std::endl;
    std::cout << "TEST 2: std::list (reference)" << std::endl;
    std::cout << "============================" << std::endl;

    std::list<int> lst;
    
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);

    std::cout << "Iteration (list behavior):" << std::endl;
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
        std::cout << *it << std::endl;

    std::cout << "\n============================" << std::endl;
    std::cout << "TEST 3: consistency check" << std::endl;
    std::cout << "============================" << std::endl;

    std::cout << "Both should print same sequence: 10 20 30 40" << std::endl;

    std::cout << "\nMutantStack iteration:" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << " ";

    std::cout << "\nList iteration:" << std::endl;
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
        std::cout << *it << " ";

    std::cout << std::endl;

    return 0;
}