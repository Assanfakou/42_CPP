#ifndef ROBOTOMY_REQUEST_FORM
#define ROBOTOMY_REQUEST_FORM

#include <iostream>
#include "AForm.h"

class RobotomyRequestForm : public AForm
{
    private:
      std::string target;
    public:
      RobotomyRequestForm(const std::string& target_);
      RobotomyRequestForm(const RobotomyRequestForm &other);
      RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
      ~RobotomyRequestForm();

      void action() const ;
};

#endif
