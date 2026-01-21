#include "easyfind.h"
#include <iostream>
#include <exception>
#include <vector>
#include <list>

int main(void) {
	std::vector<int> tmpVector;
	std::list<int> tmpList;

	tmpVector.push_back(5);
	tmpVector.push_back(7);
	tmpVector.push_back(1);
	tmpVector.push_back(4);
	tmpVector.push_back(2);

	tmpList.push_back(7);
	tmpList.push_back(9);
	tmpList.push_back(4);
	
	const std::vector<int>& v1 = tmpVector;
	const std::list<int>& list1 = tmpList;

	std::cout << "==== SUCCESS ====" << std::endl;
	try {
		const std::vector<int>::const_iterator itVector = easyfind(v1, 4);
		const std::list<int>::const_iterator itList = easyfind(list1, 4);

		std::cout << "Vector: " << *itVector << "\t | pos: " << std::distance(v1.begin(), itVector) << std::endl;
		std::cout << "List: " << *itList << "\t\t | pos: " << std::distance(list1.begin(), itList) << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n==== ERROR ====" << std::endl;
	try {
		const std::vector<int>::const_iterator itVector = easyfind(v1, 99);
		const std::list<int>::const_iterator itList = easyfind(list1, 99);

		std::cout << "Vector: " << *itVector << " | pos: " << std::distance(v1.begin(), itVector) << std::endl;
		std::cout << "List: " << *itList << " | pos: " << std::distance(list1.begin(), itList) << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}