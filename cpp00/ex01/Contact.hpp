#ifndef CONTACT_HPP
#define CONTACT_HPP

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
			std::cout << "Phone Number : " << p_Number << std::endl; std::cout << "Darkest Secret : " << darkest_Secret << std::endl;
		}
};
# endif
