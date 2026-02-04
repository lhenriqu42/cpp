#pragma once

#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <iostream>

#include "Colors.h"

class RPN {
	private:
		std::stack<int> _stack;
	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		// UTILS
		static int atoi(std::string str);
		static std::string trim(const char* str);
		static std::string trim(const std::string& str);
		static std::vector<std::string> split(const std::string &s, const char *delimiters);
		// MAIN FUNCTION
	
		void evaluate(std::vector<std::string> tokens);
};