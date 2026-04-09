#include "easyfind.h"

easyfind::easyfind(void)
{
}

easyfind::easyfind(/*parameters*/)
{
}

easyfind::easyfind(const easyfind &other)
{
        *this = other;
}

easyfind &easyfind::operator=(const easyfind &other)
{
        if (this != &other)
        {
                // _member = other._member;
        }
        return (*this);
}

easyfind::~easyfind()
{
}
