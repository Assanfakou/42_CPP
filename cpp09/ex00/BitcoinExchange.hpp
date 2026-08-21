# pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <cstdlib>

class BitcoinExchange {
	private:
		std::map<std::string, float> data;

		float getRate(const std::string &date);
		bool check_date(const std::string& date);
		bool check_value(const std::string& value, float &reVsult);
	public:
		BitcoinExchange();
		BitcoinExchange(const std::string &filename);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		std::string trim(const std::string &str) const;

		void loadDatabase(const std::string &filename);
		void processInput(const std::string &filename);
		void print_map() ;
		
	class FileIssue : public std::exception {
		const char *what() const throw ();
	};
};
