#include "BitcoinExchange.hpp"

int main (int ac, char *av[])
{
	(void)ac;
	if (ac < 2)
		return 1;
	try
	{
		BitcoinExchange btc;

		btc.loadDatabase("db.csv");
		btc.processInput(av[1]);
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
}
