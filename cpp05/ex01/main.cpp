#include "Bureaucrat.h"
#include "Form.h"
#include <iostream>

int main()
{
    std::cout << "----- VALID SIGNING -----" << std::endl;
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

    std::cout << "\n----- GRADE TOO LOW TO SIGN -----" << std::endl;
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

    std::cout << "\n----- SIGNING ALREADY SIGNED FORM -----" << std::endl;
    try
    {
        Bureaucrat manager("Manager", 1);
        Form report("Report", 10, 10);

        manager.signForm(report);
        manager.signForm(report); // second attempt
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n----- INVALID FORM GRADES -----" << std::endl;
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

