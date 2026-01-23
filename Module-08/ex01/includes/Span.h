#pragma once

#include <exception>
#include "Colors.h"
class Span {
	private:
		Span(){};
		unsigned int _size;
		int* _array;
	public:
		// Ortodox Canonical Form
		Span(unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int number);
		void addNumbers(int* numbers, unsigned int count);

		int shortestSpan() const;
		int longestSpan() const;

		class SpanFullException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return RED "Span is already full." RESET;
				}
		};

		class NotEnoughNumbersException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return RED "Span must contain at least two numbers to find a span." RESET;
				}
		};
};