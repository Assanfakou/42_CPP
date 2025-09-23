#include <iostream>
#include <string>

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
		void set_f_name(void)
		{
			std::string line;
			while (line.empty())
			{
				std::cout <<"First Name :";
				std::getline(std::cin, line);
				if (line.empty())
					std::cout <<"please enter your First Name\n";
			}
			this->f_Name = line;
		}
		void set_l_name(void)
		{
			std::string line;

			while (line.empty())
			{
				std::cout <<"Last Name :";
				std::getline(std::cin, line);
				if (line.empty())
					std::cout <<"please enter your Last Name\n";
			}
			this->l_Name = line;
		}
		void set_nickname(void)
		{
			std::string line;

			while (line.empty())
			{
				std::cout <<"Nickname :";
				std::getline(std::cin, line);
				if (line.empty())
					std::cout <<"please enter your nickname\n";
			}
			this->nickname = line;
		}
		void set_p_number(void)
		{
			std::string line;

			while (line.empty())
			{
				std::cout <<"Phone Number :";
				std::getline(std::cin, line);
				if (line.empty())
					std::cout <<"please enter your Phone Number\n";
			}
			this->p_Number = line;
		}
		void set_darkest_secret(void)
		{
			std::string line;

			while (line.empty())
			{
				std::cout <<"Darkes Secret :";
				std::getline(std::cin, line);
				if (line.empty())
					std::cout <<"please enter your Darkest Secret\n";
			}
			this->darkest_Secret = line;
		}
		void print()
		{
			std::cout << f_Name << std::endl;
			std::cout << l_Name << std::endl;
			std::cout << nickname << std::endl;
			std::cout << p_Number << std::endl;
			std::cout << darkest_Secret << std::endl;
		}
};

int main ()
{
	std::string command;
	std::string line;
	Contact con;

	while (1)
	{
		std::cout << "ADD || SEARCH || EXIT :";
		std::getline(std::cin, command);
		if (command.compare("ADD") == 0)
		{
			con.set_f_name();
			con.set_l_name();
			con.set_nickname();
			con.set_p_number();
			con.set_darkest_secret();
		}
		con.print();
	}
}
