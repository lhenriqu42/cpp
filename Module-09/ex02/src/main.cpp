#include "PmergeMe.hpp"
#include "Colors.h"
#include <iostream>

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << RED << "Error: Invalid number of arguments." << RESET << std::endl;
		std::cerr << "Usage: " << argv[0] << " \"<Sequence of positive integers>\"" << std::endl;
		return 1;
	}

	PmergeMe pmergeMe;
	
	// Further processing with pmergeMe can be done here

	return 0;
}