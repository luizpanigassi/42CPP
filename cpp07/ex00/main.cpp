#include "Whatever.hpp"

int main()
{
	std::cout << "----- TESTING INT -----" << std::endl;

	int a = 2;
	int b = 3;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << std::endl;
	std::cout << "min(a, b) = " << min(a,b) << std::endl;
	std::cout << "max(a, b) = " << max(a,b) << std::endl;
	std::cout << std::endl;
	std::cout << "Swapping a and b..." << std::endl;
	swap(a,b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << std::endl;

	std::cout << "----- TESTING STRING -----" << std::endl;
	std::string c = "string 1";
	std::string d = "string 2";
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << std::endl;
	std::cout << "min(c, d) = " << min(c,d) << std::endl;
	std::cout << "max(c, d) = " << max(c,d) << std::endl;
	std::cout << std::endl;
	std::cout << "Swapping c and d..." << std::endl;
	swap(c,d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << std::endl;

	std::cout << "----- TESTING FLOAT -----" << std::endl;
	float e = 1.5f;
	float f = 2.5f;
	std::cout << "e = " << e << "f, f = " << f << "f" << std::endl;
	std::cout << std::endl;
	std::cout << "min(e, f) = " << min(e,f) << "f" << std::endl;
	std::cout << "max(e, f) = " << max(e,f) << "f" << std::endl;
	std::cout << std::endl;
	std::cout << "Swapping e and f..." << std::endl;
	swap(e,f);
	std::cout << "e = " << e << "f, f = " << f << "f" << std::endl;
	std::cout << std::endl;

	std::cout << "----- TESTING DOUBLE -----" << std::endl;
	double g = 5.5;
	double h = 3.5;
	std::cout << "g = " << g << ", h = " << h << std::endl;
	std::cout << std::endl;
	std::cout << "min(g, h) = " << min(g,h) << std::endl;
	std::cout << "max(g, h) = " << max(g,h) << std::endl;
	std::cout << std::endl;
	std::cout << "Swapping g and h..." << std::endl;
	swap(g,h);
	std::cout << "g = " << g << ", h = " << h << std::endl;
	std::cout << std::endl;

	return 0;
}
