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
bool BitcoinExchange::check_date(const std::string& date)
{
	if (date.size() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	for (size_t i = 0; i < 10; i++)
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
		return false;
	return true;
}
		
bool BitcoinExchange::check_value(const std::string& value, float &result)
{
	if (value.empty())
	{
		std::cerr << "Empty value \n";
		return false;
	}
	int dot = 0;
	for (size_t i = 0; i < value.size(); i++)
	{
		if (i == 0 && value[i] == '-')
			continue;
		if (value[i] == '.')
		{
			dot++;
			if (dot > 1)
			{
				std::cerr << "value has more than dots" << '\n';
				return false;
			}
			continue;
		}
		if (!std::isdigit(value[i]))
		{
			std::cerr << "Not a digit \n";
			return false;
		}
	}
	result = std::atof(value.c_str());
	if (result < 0)
	{
		std::cerr << "result is Negative \n";
		return false;
	}
	if (result > 1000)
	{
		std::cerr << "result is too large \n";
		return false;
	}
	return true;
}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::ifstream datafile(filename.c_str());
	std::string line;
	std::string date;
	std::string value;
	size_t comma = 0;

	int lin = 0;
	if (!datafile.is_open())
		throw FileIssue();
	std::getline(datafile, line);
	while (std::getline(datafile, line))
	{
		lin++;
		std::cout << lin << std::endl;
		comma = line.find(",");
		if (comma == std::string::npos)
			continue;
		date = line.substr(0, comma);
		value = line.substr(comma + 1);
		data[date] = atof(value.c_str());
	}
	print_map();
}

void BitcoinExchange::processInput(const std::string &filename)
{
	std::ifstream inputFile(filename.c_str());
	std::string line;
	std::string date;
	std::string amount;
	size_t delemeter = 0;

	if (!inputFile.is_open())
		throw FileIssue();
	std::getline(inputFile, line);
	while (std::getline(inputFile, line))
	{
		float num;
		delemeter = line.find("|");
		if (delemeter == std::string::npos)
			continue;
		date = line.substr(0, delemeter);
		amount = line.substr(delemeter + 1);
		if (!check_date(date))
		{
			std::cerr << "date formula issue\n";
			continue;
		}
		if (!check_value(amount, num))
			continue;
		std::cout << date << " " << amount << " \n";
	}
}
BitcoinExchange::~BitcoinExchange()
{
}
