#include "iter.hpp"

int main()
{
	std::string strArray[] = {"Hi", "Oi", "Bonjour", "Ciao"};
	int intArray[] = {1, 2, 3, 4};


	std::cout << "--- String array before iter (using printString) ---" << std::endl;
	iter(strArray, 4, printString);
	std::cout << std::endl;
	std::cout << "--- String array after iter (using toUpperString) ---" << std::endl;
	iter(strArray, 4, toUpperString);
	iter(strArray, 4, printString);
	std::cout << std::endl;
	std::cout << "--- Int array before iter (using printInt) ---" << std::endl;
	iter(intArray, 4, printInt);
	std::cout << std::endl;
	std::cout << "--- Int array after iter (using incrementInt) ---" << std::endl;
	iter(intArray, 4, incrementInt);
	iter(intArray, 4, printInt);

	return 0;
}
