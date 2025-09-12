#include "Span.hpp"

int main()
{
	srand(time(NULL));
	std::cout << std::endl;
	std::vector<int> vec;
	std::cout << "Creating a 100-int vector and filling it with random numbers..." << std::endl;
	Span sp = Span(100);
	try
	{
		sp.fillRandomNumbers(100);
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "Creating a 10-int vector and filling it with 5 hardcoded numbers..." << std::endl;
	Span sp2 = Span(10);
	try
	{
		sp2.addNumber(5);
		sp2.addNumber(10);
		sp2.addNumber(25);
		sp2.addNumber(12);
		sp2.addNumber(1);
		std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp2.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	std::cout << "Creating a 10-int vector and filling it with 11 hardcoded numbers..." << std::endl;
	Span sp3 = Span(10);
	try
	{
		sp3.addNumber(5);
		sp3.addNumber(10);
		sp3.addNumber(25);
		sp3.addNumber(12);
		sp3.addNumber(1);
		sp3.addNumber(22);
		sp3.addNumber(34);
		sp3.addNumber(90);
		sp3.addNumber(66);
		sp3.addNumber(142);
		sp3.addNumber(1);
		std::cout << "Shortest Span: " << sp3.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp3.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	return 0;
}
