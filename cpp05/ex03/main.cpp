#include "Intern.h"
#include "Bureaucrat.h"
#include "AForm.h"
#include "colors.h"

int main()
{
    Intern someRandomIntern;
    Bureaucrat boss("Boss", 1);
    AForm* form;

    std::cout << Green << "\n-------Shrubbery Creation ----------\n" << RESET;
    form = someRandomIntern.makeForm("Shrubbery Creation", "Home");
    if (form)
    {
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }

    std::cout << Green << "\n------ Robotomy Request ------\n" << RESET;
    form = someRandomIntern.makeForm("Robotomy Request", "Bender");
    if (form)
    {
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }

    std::cout << Green << "\n------- Presidential Pardon --------\n" << RESET;
    form = someRandomIntern.makeForm("Presidential Pardon", "Marvin");
    if (form)
    {
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }

    std::cout << Green << "\n----------Unknown Form-----------\n" << RESET;
    form = someRandomIntern.makeForm("unknown form", "Nobody");
    if (!form)
        std::cout << "Form creation failed as expected\n";

    return 0;
}
