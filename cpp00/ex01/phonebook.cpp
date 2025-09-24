#include <iostream>
#include <string>

#define RED "\033[0;31m"
#define RESET "\033[0m"

class Contact
{
	std::string f_Name;
	std::string l_Name;
	std::string nickname;
	std::string p_Number;
	std::string darkest_Secret;
	public:
		Contact()
		{
			f_Name = "";
			l_Name = "";
			nickname = "";
			p_Number = "";
			darkest_Secret = "";
		}
		void set_f_name(std::string f_Name)
		{
			this->f_Name = f_Name;
		}
		void set_l_name(std::string l_Name)
		{
			this->l_Name = l_Name;
		}
		void set_nickname(std::string Nickname)
		{
			this->nickname = Nickname;
		}
		void set_p_number(std::string Number)
		{
			this->p_Number = Number;
		}
		void set_darkest_secret(std::string DarkSecret)
		{
			this->darkest_Secret = DarkSecret;
		}
		std::string get_f_name()
		{
			return this->f_Name;
		}
		std::string get_l_name()
		{
			return this->l_Name;
		}
		std::string getNickname()
		{
			return this->nickname;
		}
		std::string getP_Number()
		{
			return this->p_Number;
		}
		std::string getDarkestSecret()
		{
			return this->darkest_Secret;
		}
		void print_data()
		{
			std::cout << "First Name : " << f_Name << std::endl;
			std::cout << "Last Name : " << l_Name << std::endl;
			std::cout << "Nickname : " << nickname << std::endl;
			std::cout << "Phone Number : " << p_Number << std::endl;
			std::cout << "Darkest Secret : " << darkest_Secret << std::endl;
		}
};

class PhoneBook
{
	Contact contact[8];
};

void print_table(int i)
{
	if (i == 0)
	{
		std::cout << "--------------------------------------------" << std::endl;
		std::cout << "      index|First Name |Last Name |Nickname |" << std::endl;
		std::cout << "--------------------------------------------" << std::endl;
	}
	else
		std::cout << "--------------------------------------------" << std::endl;
}

std::string get_line(std::string to_get)
{

	std::string line;
	while (line.empty())
	{
		std::cout << to_get;
		std::getline(std::cin, line);
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

	while (line.compare("EXIT"))
	{
		std::cout << "ADD || SEARCH || EXIT :";
		std::getline(std::cin, command);
		if (!command.compare("ADD"))
		{
			con.set_f_name(get_line("First Name : "));
			con.set_l_name(get_line("Last Name : "));
			con.set_nickname(get_line("Nickname : "));
			con.set_p_number(get_line("Phone Number : "));
			con.set_darkest_secret(get_line("Darkest Secret : "));
		}
		else if (!command.compare("SEARCH"))
		{
			con.print_data();
		}
		else if (!command.compare("EXIT"))
			return 0;
	}
}
