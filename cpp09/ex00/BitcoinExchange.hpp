# pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cstdlib>

class BitcoinExchange {
	private:
		std::map<std::string, float> data;

		bool  isValidDate(const std::string &date);
		float getRate(const std::string &date);
	public:
		BitcoinExchange();
		BitcoinExchange(const std::string &filename);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		bool check_date(const std::string& date);
		bool check_value(const std::string& value, float &result);
		void loadDatabase(const std::string &filename);
		void processInput(const std::string &filename);
		void print_map() ;
		
	class FileIssue : public std::exception {
		const char *what() const throw (){
			return "File Issue";
		}
	};
};
