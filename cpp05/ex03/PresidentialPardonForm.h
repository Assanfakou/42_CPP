#ifndef PRESIDENTIAL_PARDON_FORM
#define PRESIDENTIAL_PARDON_FORM

#include "AForm.h"

class PresidentialPardonForm : public AForm
{
    private:
      std::string target;
    public:
      PresidentialPardonForm(const std::string& target_);
      PresidentialPardonForm(const PresidentialPardonForm &other);
      PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
      ~PresidentialPardonForm();

      void action() const ;
};

#endif
