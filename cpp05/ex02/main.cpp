#include "Bureaucrat.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"
#include "colors.h"

int main()
{
    try
    {
        std::cout << Green << "\n========== BUREAUCRATS ==========\n\n" << RESET;
        Bureaucrat boss("The Big Boss", 1);
        Bureaucrat intern("Sad Intern", 150);
        Bureaucrat middleMan("Middle Manager", 40);

        std::cout << boss << "\n";
        std::cout << intern << "\n";
        std::cout << middleMan << "\n\n\n";

        std::cout << Green << "\n========== FORMS ==========\n\n" << RESET;
        ShrubberyCreationForm shrub("Garden");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Enemy");

        std::cout << shrub << "\n";
        std::cout << robot << "\n";
        std::cout << pardon << "\n\n\n";

        std::cout << Green << "\n========== TESTING SHRUBBERY ==========\n\n" << RESET;
        intern.executeForm(shrub);
        boss.signForm(shrub);
        intern.executeForm(shrub);
        middleMan.executeForm(shrub);
        std::cout << "\n\n";

        std::cout << Green << "\n========== TESTING ROBOTOMY ==========\n\n" << RESET;
        middleMan.signForm(robot);
        middleMan.executeForm(robot); 
        boss.executeForm(robot);
        std::cout << "\n\n";


        std::cout << Green << "\n========== TESTING PARDON  ==========\n\n" << RESET;
        middleMan.signForm(pardon);
        boss.signForm(pardon);
        middleMan.executeForm(pardon);
        boss.executeForm(pardon);
        std::cout << "\n\n";
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << "\n";
    }
}