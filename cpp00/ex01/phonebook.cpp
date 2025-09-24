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
	Contact contacts[8];
	int index;
	int size;
	public:
		PhoneBook()
		{
			index = 0;
			size = 0;
		}
		void addContact(const Contact& c)
		{
			contacts[index] = c;
			index = (index + 1) % 8;
			if (size < 8)
				size++;
		}
		int get_size()
		{
			return size;
		}
		void prinTable();
};

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
		if (line == "")
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
		if (command == "")
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
			p.prinTable();
		}
		else if (!command.compare("EXIT"))
			return 0;
	}
}
