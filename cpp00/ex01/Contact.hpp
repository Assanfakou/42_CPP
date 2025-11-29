#ifndef CONTACT_HPP
# define CONTACT_HPP
#include <iostream>

class Contact
{
	std::string f_Name;
	std::string l_Name;
	std::string nickname;
	std::string p_Number;
	std::string darkest_Secret;
	public:
		Contact();
		void set_f_name(const std::string& f_Name);
		void set_l_name(const std::string& l_Name);
		void set_nickname(const std::string& Nickname);
		void set_p_number(const std::string& Number);
		void set_darkest_secret(const std::string& DarkSecret);
		std::string get_f_name();
		std::string get_l_name();
		std::string getNickname();
		std::string getP_Number();
		std::string getDarkestSecret();
		void print_data();
		
};

bool checkPrintable(const std::string& line);

# endif
