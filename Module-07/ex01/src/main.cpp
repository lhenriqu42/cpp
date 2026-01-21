/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:51:07 by gangel-a          #+#    #+#             */
/*   Updated: 2026/01/21 13:58:45 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "iter.h"

void printInt(const int& x) {
	std::cout << x << std::endl;
}

void printString(const std::string& str) {
	std::cout << str << std::endl;
}

void increment(int& x) {
	x++;
}

int main() {
	std::cout << YEL "------------------------------INTS------------------------------" RESET << std::endl;

	int arr[] = {1, 2, 3, 4, 5};
	std::size_t len = sizeof(arr) / sizeof(arr[0]);

	std::cout << MAG "Original array:" RESET << std::endl; 
	iter(arr, len, printInt);
	std::cout << std::endl;

	std::cout << BLU "incrementing..." RESET << std::endl;
	iter(arr, len, increment);

	std::cout << MAG "Incremented array:" RESET << std::endl;
	iter(arr, len, printInt);
	std::cout << std::endl;

	std::cout << YEL "------------------------------CONST STRINGS------------------------------" RESET << std::endl;
	
	const std::string carr[] = {"TEST1", "TEST2", "TEST3", "TEST4"};
	std::size_t clen = sizeof(carr) / sizeof(carr[0]);

	std::cout << MAG "String array:" RESET << std::endl;
	iter(carr, 	clen, printString);
}
