#pragma once

#include "Colors.h"
#include <ctime>
#include <deque>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <iomanip>



class PmergeMe
{
  private:
	PmergeMe();

  public:
	PmergeMe(char *argv[]);
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	// UTILS
	static int atoi(std::string str);
	static std::string trim(const char *str);
	static std::string trim(const std::string &str);
	static std::vector<std::string> split(const std::string &s,	const char *delimiters);

	// FUNCTIONS
	std::vector<int> jacobsthalSequence(int n);

	template <typename T>
	void binaryInsert(T &sorted, typename T::value_type value)
	{
		typename T::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), value);
		sorted.insert(pos, value);
	}

	template <typename T>
	T fordJohnsonSort(T &container)
	{
		size_t size = container.size();
		if (size <= 1)
			return container;
		
		T main, pend;
		for (size_t i = 0; i < size; i += 2)
		{
			if (i + 1 < size)
			{
				if (container[i] < container[i + 1])
				{
					main.push_back(container[i + 1]);
					pend.push_back(container[i]);
				}
				else
				{
					main.push_back(container[i]);
					pend.push_back(container[i + 1]);
				}
			}
			else
			{
				main.push_back(container[i]);
			}
		}

		main = fordJohnsonSort(main);

		std::vector<int> jacob = jacobsthalSequence(pend.size());
		std::vector<bool> inserted(pend.size(), false);

		for (size_t i = 1; i < jacob.size(); ++i)
		{
			int idx = jacob[i];
			if (idx >= 0 && idx < (int)pend.size() && !inserted[idx])
			{
				binaryInsert(main, pend[idx]);
				inserted[idx] = true;
			}
		}

		for (size_t i = 0; i < pend.size(); ++i)
		{
			if (!inserted[i])
				binaryInsert(main, pend[i]);
		}

		return main;
	}
};