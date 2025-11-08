#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include "Contact.hpp"

#define RED "\033[0;31m"
#define RESET "\033[0m"

class PhoneBook
{
	Contact contacts[8];
	int index;
	int size;
	public:
		PhoneBook();
		void addContact(const Contact& c);
		int get_size();
		void prinTable();
		void print_index(int index);
};

std::string formatField(const std::string& str);
std::string get_line(std::string to_get);
# endif
