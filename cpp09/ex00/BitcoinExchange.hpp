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

		void loadDatabase(const std::string &filename);
		void processInput(const std::string &filename);
		void print_map() ;
		
	class FileIssue : public std::exception {
		const char *what() const throw (){
			return "File Issue";
		}
	};
	class NegativeValue : public std::exception {
		const char *what() const throw (){
			return "Positive values only";
		}
	};
	class TooLargeNum : public std::exception {
		const char *what() const throw(){
			return "Value is Too large Value > 1000";
		}
	};
	class TimeFormat : public std::exception {
		const char *what() const throw (){
			return "Bad Time Formula";
		}
	};
	class NonNumirique : public std::exception {
		const char *what() const throw(){
			return "Bad Input here ";
		}
	};
};
