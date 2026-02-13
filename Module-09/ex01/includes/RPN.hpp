#pragma once

#include <stack>
#include <string>
#include <list>
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
		static std::list<std::string> split(const std::string &s, const char *delimiters);
		// MAIN FUNCTION
	
		void evaluate(std::list<std::string> tokens);
};