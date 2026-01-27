#include "Intern.h"
#include "AForm.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"

Intern::Intern() {}

Intern::Intern(const Intern &other)
{
        (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
        (void)other;
        return (*this);
}

AForm * creatShrebbery(const std::string& target)
{
        return new ShrubberyCreationForm(target);
}

AForm * creatRobotomy(const std::string& target)
{
        return new RobotomyRequestForm(target);
}

AForm * creatPresidential(const std::string& target)
{
        return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
        std::string names[3] =
        {"Shrubbery Creation", 
         "Robotomy Request",
         "Presidential Pardon"
         };
        
        AForm *(*links[3])(const std::string&) = {
                &creatShrebbery,
                &creatRobotomy,
                &creatPresidential,
        };

        for (int i = 0; i < 3; i++)
        {
                if (name == names[i])
                {
                        std::cout << "Intern created for " << name << '\n';
                        return (links[i](target));
                }
        }
        std::cout << "Intern cannot create this " << name << '\n';
        return NULL;
}
Intern::~Intern() {}
