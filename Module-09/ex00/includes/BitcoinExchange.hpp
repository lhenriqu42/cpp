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
		Database _db;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void performExchange(const char *inputFilePath);

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