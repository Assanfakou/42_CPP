#include "RobotomyRequestForm.h"
#include <fstream>
#include <cstdlib>


RobotomyRequestForm::RobotomyRequestForm(const std::string& target_) : 
        AForm("Robotomy", 72, 45), 
        target(target_) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : 
        AForm(*this), 
        target(other.target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
        if (this != &other)
        {
                AForm::operator=(other);
                target = other.target;
        }
        return (*this);
}
void RobotomyRequestForm::action() const
{
        std::srand(time(0));
        int num = rand();

        std::cout << "Noiiise here \n";
        if (num % 2 == 0)
                std::cout << target << " has been Robotmized successfully \n";
        else
                std::cout << target << " has been failed to Robotmized \n";
}

RobotomyRequestForm::~RobotomyRequestForm() {}
