#pragma once
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <exception>
#include "Colors.h"

typedef std::map<std::string, double> Database;
class BitcoinExchange
{
	private:
		BitcoinExchange() {};
	public:
		BitcoinExchange(const char *dataFilePath);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();


		void performExchange(const std::string &date, double amount);

		class FileNotFoundException : public std::exception
		{
			private:
				FileNotFoundException() {};
				std::string _message;
			public:
				FileNotFoundException(std::string message) : _message(YEL + message + RESET) {}
				~FileNotFoundException() throw() {}
				virtual const char *what() const throw()
				{
					return _message.c_str();
				}
		};
};