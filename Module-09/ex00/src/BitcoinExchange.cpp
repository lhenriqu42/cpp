
#include "BitcoinExchange.hpp"

// ---------------------------------------------- PARSER ----------------------------------------------

std::string trim(const std::string& str)
{
	size_t first = str.find_first_not_of(" \t\n\r");
	if (first == std::string::npos) return "";
	size_t last = str.find_last_not_of(" \t\n\r");
	return str.substr(first, (last - first + 1));
}

double atod(std::string str)
{
	double rate;
	std::istringstream iss(str);

	iss >> rate;

	if (iss.fail())
		throw std::invalid_argument("bad input " + str);

	if (rate < 0)
		throw std::invalid_argument("not a positive number " + str);

	return (rate);
}

int atoi(std::string str)
{
	int value;
	std::istringstream iss(str);

	iss >> value;

	if (iss.fail())
		throw std::invalid_argument("bad input " + str);

	return (value);
}

std::vector<std::string> split(const std::string &s, char *delimiters)
{
	std::vector<std::string> tokens;
	size_t start = 0;
	size_t end = s.find_first_of(delimiters);

	while (end != std::string::npos)
	{
		tokens.push_back(s.substr(start, end - start));
		start = end + 1;
		end = s.find_first_of(delimiters, start);
	}
	tokens.push_back(s.substr(start));
	return tokens;
	
}

void loadCsv( Database &db, std::ifstream &csvFile)
{ 
	std::string line;
	// Skip header
	std::getline(csvFile, line);
	while (std::getline(csvFile, line))
	{
		size_t commaPos = line.find(',');
		if (commaPos != std::string::npos)
		{
			std::string date = trim(line.substr(0, commaPos));
			double value = atod(trim(line.substr(commaPos + 1)));
			db[date] = value;
		}
	}
}

void validateDate(const std::string &date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		throw std::invalid_argument("bad input => " + date + " - bad date format ");

	int year = atoi(date.substr(0, 4));
	int month = atoi(date.substr(5, 2));
	int day = atoi(date.substr(8, 2));

	if (month < 1 || month > 12)
		throw std::invalid_argument("bad input => " + date + " - invalid month in date ");
	if (day < 1 || day > 31)
		throw std::invalid_argument("bad input => " + date + " - invalid day in date ");
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		throw std::invalid_argument("bad input => " + date + " - invalid day in date ");
	if (month == 2)
	{
		bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (day > (isLeap ? 29 : 28))
			throw std::invalid_argument("bad input => " + date + " - invalid day in date ");
	}
}

void printExchange(const Database &db, const std::string &date, double amount)
{
	// VALIDAR SE ESTA CORRETO

	Database::const_iterator it = db.lower_bound(date);
	if (it == db.end() || it->first != date)
	{
		if (it == db.begin())
			throw std::invalid_argument("no exchange rate available for date " + date);
		--it;
	}
	double rate = it->second;
	double result = rate * amount;
	std::cout << date << " => " << amount << " = " << result << std::endl;
}

void printLineResult(const Database &db, const std::vector<std::string> &strings)
{
	std::string date = strings[0];
	if (date.empty())
		throw std::invalid_argument("empty line");

	validateDate(date);

	if (strings.size() == 2)
	{
		std::string amount = strings[1];
		if (amount == "|")
			throw std::invalid_argument("missing amount for date " RESET + date);
		else
			throw std::invalid_argument("missing separator '|' for date " RESET + date);
	}

	if (strings.size() != 3)
		throw std::invalid_argument("too many arguments in line for date " RESET + date);
	
	double amount = atod(strings[2]);

	printExchange(db, date, amount);
	
}


void printResults(const Database &db, std::ifstream &inputFile)
{
	std::string line;
	// Skip header
	std::getline(inputFile, line);
	while (std::getline(inputFile, line))
	{
		std::vector<std::string> strings = split(trim(line), " \t\n\r");
		try {
			printLineResult(db, strings);
		} catch (std::exception &e) {
			std::cout << RED "Error: " YEL << e.what() << RESET << std::endl;
		}
	}
}



// ------------------------------------------- BITCOIN EXCHANGE -------------------------------------------

BitcoinExchange::BitcoinExchange(const char *inputFilePath)
{
	std::ifstream csvFile("data.csv");
	if (!csvFile.is_open()) throw FileNotFoundException("Database file not found: " RESET "data.csv");
	Database db;
	loadCsv(db, csvFile);


	std::ifstream inputFile(inputFilePath);
	if (!inputFile.is_open()) throw FileNotFoundException("Data file not found: " RESET + std::string(inputFilePath));	
	
	printResults(db, inputFile);

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		// Assignment operator implementation
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	// Destructor implementation
}

void BitcoinExchange::performExchange(const std::string &date, double amount)
{
	// Method implementation
}