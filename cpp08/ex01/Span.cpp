#include "Span.hpp"

// Constructors and Destructor

Span::Span(unsigned int N) : _n(N){
	if (N == 0)
		throw notEnoughNumbersException();
};

Span::Span(const Span& other) : _n(other._n), vec(other.vec) {}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_n = other._n;
		vec = other.vec;
	}
	return *this;
}

Span::~Span(){}

// Functions

void Span::addNumber(int number)
{
	if(vec.size() >= _n)
		throw fullSpanException();
	vec.push_back(number);
}

void Span::fillRandomNumbers(unsigned int count)
{
	if(vec.size() + count > _n)
		throw fullSpanException();

	for(unsigned int i = 0; i < count; i++)
		vec.push_back(rand() % 10000);
}

int Span::shortestSpan() const
{
	if(vec.size() < 2)
		throw noSpanException();

	std::vector<int> sortedVec = vec;
	std::sort(sortedVec.begin(), sortedVec.end());
	int minSpan = sortedVec[1] - sortedVec[0];
	for(size_t i = 1; i < sortedVec.size(); i++)
	{
		int span = sortedVec[i] - sortedVec[i - 1];
		if(span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

int Span::longestSpan() const
{
	if(vec.size() < 2)
		throw noSpanException();

	int minVal = *std::min_element(vec.begin(), vec.end());
	int maxVal = *std::max_element(vec.begin(), vec.end());
	return maxVal - minVal;
}
