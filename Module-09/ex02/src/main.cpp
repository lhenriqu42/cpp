#include "PmergeMe.hpp"
#include "Colors.h"
#include <iostream>


int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << RED << "Usage: " << argv[0] << " <numbers...>" << RESET << std::endl;
		return 1;
	}
	
	try {
		PmergeMe pmergeMe(argv);
	} catch (const std::exception& e) {
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
		return 1;
	}

	return 0;
}