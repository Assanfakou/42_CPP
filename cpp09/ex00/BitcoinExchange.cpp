#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
		
}

BitcoinExchange::BitcoinExchange(const std::string &filename)
{
	(void) filename;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	data = other.data;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
        if (this != &other)
        {
		data = other.data;
	}
	return (*this);
}
void BitcoinExchange::print_map()
{
	std::map<std::string, float>::iterator it;

	for (it = data.begin() ; it != data.end(); ++it)
	{
		std::cout << it->first << " " << it->second << std::endl;
	}
}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::ifstream datafile(filename.c_str());
	std::string line;
	std::string date;
	std::string value;
	size_t comma = 0;

	if (!datafile.is_open())
		throw FileIssue();
	std::getline(datafile, line);
	while (std::getline(datafile, line))
	{
		comma = line.find(",");
		if (comma == std::string::npos)
			continue;
		date = line.substr(0, comma);
		value = line.substr(comma + 1);

		data[date] = atof(value.c_str());
	}
	print_map();
}

BitcoinExchange::~BitcoinExchange()
{
}
