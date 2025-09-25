#include "PhoneBook.hpp"

std::string formatField(const std::string& str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return std::string(10 - str.length(), ' ') + str;
}

void PhoneBook::prinTable()
{
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     index|First Name|Last Name |Nickname  |" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	if (size == 0)
	{
		std::cout << "|             Nothing To Display           |" << std::endl;	
		std::cout << "--------------------------------------------" << std::endl;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << "|" << "         " << i;
			std::cout << "|" << formatField(contacts[i].get_f_name());
			std::cout << "|" << formatField(contacts[i].get_l_name());
			std::cout << "|" << formatField(contacts[i].getNickname()) << "|\n";
			std::cout << "---------------------------------------------" << std::endl;
		}
	}
}

std::string get_line(std::string to_get)
{

	std::string line;
	while (line.empty())
	{
		std::cout << to_get;
		std::getline(std::cin, line);
		if (std::cin.eof())
			exit(1);
		if (line.empty())
			std::cout << "Valide argument please !" << std::endl;
	}
	return line;
}
	
int main ()
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
			return 1;
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
			std::cout << "Contact Index (-1 to cancel) : ";
			std::getline(std::cin, index);
			i = std::atoi(index.c_str());
			if (i < 0)
				continue ;
			p.print_index(i);
			
		}
		else if (!command.compare("EXIT"))
			return 0;
		else
			std::cout << "Valide argument please !" << std::endl;
	}
}
