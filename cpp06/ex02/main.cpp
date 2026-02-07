#include "Base.h"
#include "A.h"
#include "B.h"
#include "C.h"

Base* generate(void)
{
    std::srand(time(0));
    int r = std::rand() % 3;
    
    if (r == 0)
        return new A;
    else if (r == 1)
        return new B;
    else
        return new C;
}

void identify(Base* p)
{
    if (dynamic_cast<B*>(p))
        std::cout << "B\n";
    else if (dynamic_cast<A*>(p))
        std::cout << "A\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "C\n";
    else
        std::cout << "nullptr\n";
}

void identify(Base& p)
{
    try
    {
       (void)dynamic_cast<B&>(p);
        std::cout << "B\n";
        return ;
    }
    catch(...) {}
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A\n";
        return ;
    }
    catch(...) {}
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C\n";
        return ;
    }
    catch(...) {}
}

int main ()
{
    Base* b = generate();

    std::cout << "pointer here \n";
    identify(b);
    std::cout << "reference here \n";
    identify(*b);
    delete b;
}