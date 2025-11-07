#include "PhoneBook.hpp"

std::string formatField(const std::string& str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return std::string(10 - str.length(), ' ') + str;
}

std::string get_line(std::string to_get)
{
	std::string line;
	while (line.empty())
	{
		std::cout << to_get;
		std::getline(std::cin, line);
		if (std::cin.eof())
		{
			std::cout << RED << "\nEOF" << RESET << '\n';
			exit(1);
		}
		if (line.empty())
			std::cout << "Valide argument please !" << '\n';
	}
	return line;
}
	
int main(void)
{
	std::string command;
	std::string line;
	Contact con;
	PhoneBook p;

	while (line.compare("EXIT"))
	{
		std::cout << "ADD || SEARCH || EXIT :";
		std::getline(std::cin, command);
		if (std::cin.eof())
		{
			std::cout << RED << "\nEOF" << RESET << '\n';
			return 1;
		}
		if (!command.compare("ADD"))
		{
			con.set_f_name(get_line("First Name : "));
			con.set_l_name(get_line("Last Name : "));
			con.set_nickname(get_line("Nickname : "));
			con.set_p_number(get_line("Phone Number : "));
			con.set_darkest_secret(get_line("Darkest Secret : "));
			p.addContact(con);
		}
		else if (!command.compare("SEARCH"))
		{
			std::string index;
			int i;

			p.prinTable();
			while (1)
			{
				std::cout << "Contact Index (-1 to cancel) : ";
				std::getline(std::cin, index);
				i = std::atoi(index.c_str());
				if (i <= -1)
					break;
				if (i < p.get_size())
				{
					p.print_index(i);
					continue ;
				}
				else
				{
					std::cout << RED << "Naaaah" << RESET << '\n';
					continue;
				}

			}
			
		}
		else if (!command.compare("EXIT"))
			return 0;
		else
			std::cout << RED << "Valide argument please !" << RESET << '\n';
	}
}
