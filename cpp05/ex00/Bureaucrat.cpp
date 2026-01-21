#include "Bureaucrat.h"

Bureaucrat::Bureaucrat(void)
{
}

Bureaucrat::Bureaucrat(/*parameters*/)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
        *this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
        if (this != &other)
        {
                // _member = other._member;
        }
        return (*this);
}

Bureaucrat::~Bureaucrat()
{
}
