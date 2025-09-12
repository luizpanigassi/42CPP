#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span {
public:
	// Constructors and Destructor
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	// Functions
	void addNumber(int number);
	int shortestSpan() const;
	int longestSpan() const;
	void fillRandomNumbers(unsigned int count);

	// Exceptions
	class fullSpanException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "Span is full!";
			}
	};

	class noSpanException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "Not enough numbers to find a span!";
			}
	};

	class notEnoughNumbersException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "Not enough numbers to fill the Span!";
			}
	};

private:
	unsigned int _n;
	std::vector<int> vec;
};

#endif
