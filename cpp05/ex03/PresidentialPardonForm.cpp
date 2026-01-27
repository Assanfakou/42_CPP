#include "PresidentialPardonForm.h"
#include <fstream>
#include <cstdlib>

PresidentialPardonForm::PresidentialPardonForm(const std::string& target_) : 
        AForm("Presidential", 25, 5), 
        target(target_) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : 
        AForm(*this), 
        target(other.target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
        if (this != &other)
        {
                AForm::operator=(other);
                target = other.target;
        }
        return (*this);
}
void PresidentialPardonForm::action() const
{
        std::cout << target << " has been pardoned by Zaphod Beeblebrox.\n";
}

PresidentialPardonForm::~PresidentialPardonForm() {}

