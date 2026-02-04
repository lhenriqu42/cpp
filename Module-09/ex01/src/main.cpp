#include "RPN.hpp"
#include "Colors.h"
#include <iostream>

static std::vector<std::string> handle_args(char *argv[])
{
	std::vector<std::string> tokens;
	for (size_t i = 1; argv[i]; ++i)
	{
		std::vector<std::string> split_tokens = RPN::split(RPN::trim(argv[i]), " \t\n\r");
		tokens.insert(tokens.end(), split_tokens.begin(), split_tokens.end());
	}
	return tokens;
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cerr << RED << "Error: Invalid number of arguments." << RESET << std::endl;
		std::cerr << "Usage: " << argv[0] << " <RPN expression>" << std::endl;
		return 1;
	}

	std::vector<std::string> tokens = handle_args(argv);

	RPN rpnCalculator;
	
	try
	{
		rpnCalculator.evaluate(tokens);
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
		return 1;
	}

	return 0;
}