#include "Contact.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

#define RED "\033[0;31m"
#define RESET "\033[0m"

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
		void print_index(int index)
		{
			contacts[index].print_data();
		}
};
