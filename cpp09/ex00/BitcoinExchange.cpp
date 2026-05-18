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
				std::cerr << "Error : value has more than dots" << '\n';
				return false;
			}
			continue;
		}
		if (!std::isdigit(value[i]))
		{
			std::cerr << "Error : Not a digit \n";
			return false;
		}
	}
	result = std::atof(value.c_str());
	if (result < 0)
	{
		std::cerr << "Error : not A postive number \n";
		return false;
	}
	if (result > 1000)
	{
		std::cerr << "Error : Number is too large \n";
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
	// print_map();
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
		delemeter = line.find(' ');
		if (delemeter == std::string::npos)
		{
			std::cout << "there is not delemeter found\n";
			continue;
		}
		date = line.substr(0, delemeter);
		amount = line.substr(delemeter + 3);
		if (!check_date(date))
		{
			std::cerr << "Error : bad Formula => " << date << "\n";
			continue;
		}
		if (!check_value(amount, num))
			continue;
		std::cout << date << " => " << amount << " = " << getRate(date) * num << std::endl;
		// std::cout << getRate(date) << std::endl;
		// std::cout << date << " " << amount << " \n";
	}
}
float BitcoinExchange::getRate(const std::string& date)
{
	std::map<std::string, float>::iterator it;

	// for (it = data.begin(); it != data.end(); ++it)
	// {
	// 	if (date == data[date])
	// 		std::cout << "value multiplied by result = " << std::data[date]
	// }
	it = data.lower_bound(date);
	return (it->second);
}
const char* BitcoinExchange::FileIssue::what() const throw()
{
	return "FIle Issue";
}
BitcoinExchange::~BitcoinExchange()
{
}
