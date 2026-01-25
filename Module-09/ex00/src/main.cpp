#include "BitcoinExchange.hpp"
#include "Colors.h"
#include <iostream>

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << RED << "Error: Invalid number of arguments." << RESET << std::endl;
		std::cerr << CYN << "Usage: " YEL << argv[0] << " <file_name>" RESET << std::endl;
		return (1);
	}

	try
	{
		BitcoinExchange bitcoinExchange(argv[1]);
		// Further processing can be done here
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
		return (1);
	}

	return (0);
}