#include "Bureaucrat.h"
#include "Form.h"
#include <iostream>
#include "colors.h"

int main()
{
    std::cout << Green << "----- VALID SIGNING -----" << std::endl << RESET;
    try
    {
        Bureaucrat boss("Boss", 10);
        Form contract("Contract", 20, 30);

        std::cout << boss << std::endl;
        std::cout << contract << std::endl;

        boss.signForm(contract);
        std::cout << contract << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << Green << "\n----- GRADE TOO LOW TO SIGN -----" << std::endl << RESET;
    try
    {
        Bureaucrat intern("Intern", 100);
        Form secret("SecretForm", 50, 20);

        std::cout << intern << std::endl;
        intern.signForm(secret);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << Green << "\n----- INVALID FORM GRADES -----" << std::endl << RESET;
    try
    {
        Form badForm("BadForm", 0, 200);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

