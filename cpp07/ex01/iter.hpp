#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>
#include <cctype>

// Template
template <typename T, typename F>
void iter(T* array, size_t length, F func)
{
	for(size_t i = 0; i < length; i++)
		func(array[i]);
}


// Functions to test
void printString(std::string const & str)
{
	std::cout << str << std::endl;
}

void toUpperString(std::string & str)
{
	for(size_t i = 0; i < str.length(); i++)
		str[i] = std::toupper(str[i]);
}

void printInt(int const & n)
{
	std::cout << n << std::endl;
}

void incrementInt(int & n)
{
	n++;
}

#endif
