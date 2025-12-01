#include <iostream>

int main(int ac, char **av)
{
	std::string st = "hello world i'm assan";

	st.erase(6, 5);
	st.insert(6, "assan");
	std::cout << st<< std::endl;
}

	
