#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(const RPN& other) : _stack(other._stack) {}
RPN& RPN::operator=(const RPN& other) {
	if (this != &other) {
		_stack = other._stack;
	}
	return *this;
}
RPN::~RPN() {}

// --------------------------------------------------------------------------------------------------------------
// --------------------------------------------------- UTILS ----------------------------------------------------
// --------------------------------------------------------------------------------------------------------------

std::string RPN::trim(const std::string& str)
{
	size_t first = str.find_first_not_of(" \t\n\r");
	if (first == std::string::npos) return "";
	size_t last = str.find_last_not_of(" \t\n\r");
	return str.substr(first, (last - first + 1));
}

std::string RPN::trim(const char* str)
{
	return RPN::trim(std::string(str));
}


int RPN::atoi(std::string str)
{
	int value;
	std::istringstream iss(str);

	iss >> value;

	if (iss.fail())
		throw std::invalid_argument("bad input: " YEL + str);

	return (value);
}


std::list<std::string> RPN::split(const std::string &s, const char *delimiters)
{
	std::list<std::string> tokens;
	size_t start = 0;
	size_t end = s.find_first_of(delimiters);

	while (end != std::string::npos)
	{
		int n = 1;
		while (end + n < s.size() && std::string(delimiters).find(s[end + n]) != std::string::npos)
			++n;
		tokens.push_back(s.substr(start, end - start));
		start = end + n;
		end = s.find_first_of(delimiters, start);
	}
	tokens.push_back(s.substr(start));
	return tokens;
	
}

// --------------------------------------------------------------------------------------------------------------


void RPN::evaluate(std::list<std::string> tokens) {
	typedef std::list<std::string>::iterator iterator;
	for (iterator it = tokens.begin(); it != tokens.end(); ++it) {
		const std::string& token = *it;
		if (token == "+" || token == "-" || token == "*" || token == "/") {
			if (_stack.size() < 2) {
				throw std::runtime_error("Insufficient values in the expression");
			}

			int b = _stack.top(); _stack.pop();
			int a = _stack.top(); _stack.pop();
			
			int result;

			if (token == "+") result = a + b;
			else if (token == "-") result = a - b;
			else if (token == "*") result = a * b;
			else {
				if (b == 0) {
					throw std::runtime_error("Division by zero");
				}
				result = a / b;
			}

			_stack.push(result);
		} else {
			int value = atoi(token);
			if (value < 0)
				throw std::invalid_argument("Negative numbers are not allowed: " YEL + token);
			if (value > 9) 
				throw std::invalid_argument("Only single-digit numbers are allowed: " YEL + token);

			_stack.push(value);
		}
	}
	if (_stack.size() != 1) {
		throw std::runtime_error("The user input has too many values");
	}
	std::cout << "Result: " << _stack.top() << std::endl;
}