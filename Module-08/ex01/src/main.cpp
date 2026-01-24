#include "Span.h"
#include <iostream>

// // Subject main
// int	main(void)
// {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;

// 	return (0);
// }

// ------------------------ Additional main for testing -----------------------------------

int	randomNumber(int min, int max)
{
	static bool	first = true;

	if (first)
		srand(time(0));
	first = false;
	return (rand() % (max - min + 1) + min);
}

int	main(void)
{
	size_t NUMBER_OF_INSERTS = 10000;
	Span sp = Span(NUMBER_OF_INSERTS);
	std::vector<int> vec;

	for (size_t i = 0; i < NUMBER_OF_INSERTS; i++)
		vec.push_back(randomNumber(0, 1000000));

	sp.addNumbers(vec.begin(), vec.end());

	std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

	return (0);
}