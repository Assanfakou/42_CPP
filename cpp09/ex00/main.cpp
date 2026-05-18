#include "BitcoinExchange.hpp"

int main (int ac, char *av[])
{
	(void)ac;
	// if (ac < 2)
	// 	return 1;
	try
	{
		BitcoinExchange btc;

		btc.loadDatabase(av[1]);
		btc.processInput(av[2]);
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
}
