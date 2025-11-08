#include "Contact.hpp"

Contact::Contact(){}

void Contact::set_f_name(const std::string& f_Name)
{
    this->f_Name = f_Name;
}

void Contact::set_l_name(const std::string& l_Name)
{
    this->l_Name = l_Name;
}

void Contact::set_nickname(const std::string& Nickname)
{
    this->nickname = Nickname;
}

void Contact::set_p_number(const std::string& Number)
{
    this->p_Number = Number;
}

void Contact::set_darkest_secret(const std::string& DarkSecret)
{
    this->darkest_Secret = DarkSecret;
}

std::string Contact::get_f_name()
{
    return this->f_Name;
}

std::string Contact::get_l_name()
{
    return this->l_Name;
}

std::string Contact::getNickname()
{
    return this->nickname;
}

std::string Contact::getP_Number()
{
    return this->p_Number;
}

std::string Contact::getDarkestSecret()
{
    return this->darkest_Secret;
}

void Contact::print_data()
{
    std::cout << "First Name : " << f_Name << '\n';
    std::cout << "Last Name : " << l_Name << '\n';
    std::cout << "Nickname : " << nickname << '\n';
    std::cout << "Phone Number : " << p_Number << '\n'; 
    std::cout << "Darkest Secret : " << darkest_Secret << '\n';
}