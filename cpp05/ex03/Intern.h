#ifndef INTERN
#define INTERN

#include <iostream>

class AForm;

class Intern
{
      public:
        Intern();
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);
        ~Intern();

        AForm *makeForm(const std::string &name, const std::string& target);
};

#endif
