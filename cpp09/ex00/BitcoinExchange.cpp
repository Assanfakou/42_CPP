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
bool valid_date(const std::string& date)
{
	if (date.size() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			return false;
	}
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	
	if (year < 0)
		return false;
	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false
	return true;
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
		if (!check_date(date))
			throw TimeFormat(); 
		value = line.substr(comma + 1);

		data[date] = atof(value.c_str());
	}
	print_map();
}

BitcoinExchange::~BitcoinExchange()
{
}
