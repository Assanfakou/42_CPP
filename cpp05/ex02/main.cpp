#include "Bureaucrat.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"
#include "colors.h"

int main()
{
    try
    {
        Bureaucrat boss("Boss", 1);

        std::cout << Green << "Shrubbery\n" << RESET;
        ShrubberyCreationForm shrub("home");
        boss.signForm(shrub);
        boss.executeForm(shrub);

        std::cout << Green << "Roboto\n" << RESET;
        RobotomyRequestForm robot("Marvin");
        boss.signForm(robot);
        boss.executeForm(robot);

        std::cout << Green << "Presidential\n" << RESET;
        PresidentialPardonForm pardon("Arthur");
        boss.signForm(pardon);
        boss.executeForm(pardon);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}