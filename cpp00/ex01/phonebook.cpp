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
		void set_f_name(std::string f_name)
		{
			this->f_Name = f_name;
		}
		void set_l_name(std::string l_name)
		{
			this->l_Name = l_name;
		}
		void set_nickname(std::string nickname)
		{
			this->nickname = nickname;
		}
		void set_p_number(std::string p_number)
		{
			this->p_Number = p_number;
		}
		void set_darkest_secret(std::string darkSecret)
		{
			this->darkest_Secret = darkSecret;
		}
		void print()
		{
			std::cout << f_Name << " "<< std::endl;
		}
};

int main ()
{
	std::string comand;
	Contact con;

	while (1)
	{
		std::cout << "ADD || SEARCH || EXIT :";
		std::getline(std::cin, line);
		while (line.compare("ADD") == 0)
		{
			std::cout <<"First Name :";
			std::getline(std::cin, line);
		}
		std::cout << line << std::endl;
	}
	con.print();
}
