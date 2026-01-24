#include "Span.h"

Span::Span(unsigned int size) : _size(size){
	_array.reserve(size);
}

Span::Span(const Span& other) : _size(other._size) {
	*this = other;
}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_size = other._size;
		_array = other._array;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
	if (_array.size() >= _size) {
		throw std::out_of_range( RED "Span is already full" RESET);
	}
	_array.push_back(number);
}

void Span::addNumbers(iterator begin, iterator end) {
	size_t rangeSize = std::distance(begin, end);
	if (_array.size() + rangeSize > _size) {
		throw std::out_of_range( RED "Adding these numbers would exceed Span capacity" RESET);
	}
	_array.insert(_array.end(), begin, end);
}

size_t Span::shortestSpan() const {
	if (_array.size() < 2) {
		throw NotEnoughNumbersException();
	}

	std::vector<int> sortedArray = _array;
	std::sort(sortedArray.begin(), sortedArray.end());

	size_t minSpan = std::numeric_limits<size_t>::max();
	for (size_t i = 1; i < sortedArray.size(); ++i)
    	minSpan = std::min(minSpan, (size_t)(sortedArray[i] - sortedArray[i-1]));
	return minSpan;
}

size_t Span::longestSpan() const {
	if (_array.size() < 2) {
		throw NotEnoughNumbersException();
	}
	int minElement = *std::min_element(_array.begin(), _array.end());
	int maxElement = *std::max_element(_array.begin(), _array.end());
	return (maxElement - minElement);
}

