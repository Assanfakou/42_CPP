#include "ShrubberyCreationForm.h"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target_) : 
        AForm("Shrubbery", 145, 137), 
        target(target_) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : 
        AForm(*this), 
        target(other.target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
        if (this != &other)
        {
                AForm::operator=(other);
                target = other.target;
        }
        return (*this);
}
void ShrubberyCreationForm::action() const
{
        std::ofstream file((target + "Shrubbery").c_str());

        file << "       &&& &&  & &&\n";
        file << "   && &\\/&\\|& ()|/ @, &&\n";
        file << "   &\\/(/&/&||/& /_/)_&/_&\n";
        file << " &() &\\/&|()|/&\\/ '%\" & ()\n";
        file << " &_\\_&&_\\ |& |&&/&__%_/_& &&\n";
        file << "&&   && & &| &| /& & % ()& /&&\n";
        file << " ()&_---()&\\&\\|&&-&&--%---()~\n";
        file << "     &&     \\|||\n";
        file << "             |||\n";
        file << "             |||\n";
        file << "             |||\n";
        file << "       , -=-~  .-^- _\n";

        file.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}
