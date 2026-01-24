#pragma once

#include "Colors.h"
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <limits>
class Span
{
  public:
	typedef std::vector<int>::const_iterator iterator;
	typedef std::size_t size_t;
  private:
	Span(){};
	unsigned int _size;
	std::vector<int> _array;

  public:
	// Ortodox Canonical Form
	Span(unsigned int n);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	void addNumber(int number);
	void addNumbers(iterator begin, iterator end);

	size_t shortestSpan() const;
	size_t longestSpan() const;

	class NotEnoughNumbersException : public std::exception
	{
	  public:
		virtual const char *what() const throw()
		{
			return RED "Span must contain at least " YEL "two" RED " numbers to find a span." RESET;
		}
	};
};