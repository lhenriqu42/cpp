#include "Span.h"

Span::Span(unsigned int size) : _size(size){
	_array = new int[size];
}

Span::Span(const Span& other) : _size(other._size) {
	*this = other;
}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_size = other._size;
		if (_array)
			delete[] _array;
		_array = new int[_size];
		for (unsigned int i = 0; i < _size; i++) {
			_array[i] = other._array[i];
		}
	}
	return *this;
}

Span::~Span() {
	delete[] _array;
}

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Span::addNumber(int number) {
	for (unsigned int i = 0; i < _size; i++) {
		if (_array[i] == 0) {
			_array[i] = number;
			return;
		}
	}
	throw SpanFullException();
}