#ifndef SHRUBBERY_CREATION_FORM
#define SHRUBBERY_CREATION_FORM

#include "AForm.h"
#include <iostream>

class ShrubberyCreationForm : public AForm
{
    private:
      std::string target;
    public:
      ShrubberyCreationForm(const std::string& target_);
      ShrubberyCreationForm(const ShrubberyCreationForm &other);
      ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
      ~ShrubberyCreationForm();

      void action() const ;
};

#endif
