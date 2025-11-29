#include "PhoneBook.hpp"

void PhoneBook::prinTable()
{
	std::cout << "---------------------------------------------" << '\n';
	std::cout << "|     index|First Name|Last Name |Nickname  |" << '\n';
	std::cout << "---------------------------------------------" << '\n';
	if (size == 0)
	{
		std::cout << "|             Nothing To Display            |" << '\n';	
		std::cout << "---------------------------------------------" << '\n';
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << "|" << "         " << i;
			std::cout << "|" << formatField(contacts[i].get_f_name());
			std::cout << "|" << formatField(contacts[i].get_l_name());
			std::cout << "|" << formatField(contacts[i].getNickname()) << "|\n";
			std::cout << "---------------------------------------------" << '\n';
		}
	}
}

void PhoneBook::addContact(const Contact& c)
{
    contacts[index] = c;
    index = (index + 1) % 8;
    if (size < 8)
        size++;
}

PhoneBook::PhoneBook() : index(0), size(0) {}

void PhoneBook::print_index(int index) {
	contacts[index].print_data();
}

int PhoneBook::PhoneBook::get_size() {
	return size;
}