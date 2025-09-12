#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
public:
	// Constructors and Destructor
	Array();
	Array(unsigned int n);
	Array(const Array& other);
	Array& operator=(const Array& other);
	~Array();

	unsigned int size() const;

	// Operators
	T& operator[](unsigned int index);
	const T& operator[](unsigned int index) const;

private:
	unsigned int _size;
	T* _array;
};

#include "Array.tpp"

#endif
