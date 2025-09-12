#include "Array.hpp"

int main ()
{
	std::cout << std::endl;
	std::cout << "--------- Testing empty array ---------" << std::endl;
	std::cout << std::endl;
	Array<int> emptyArray;
	std::cout << "This array has " << emptyArray.size() << " elements." << std::endl;
	std::cout << std::endl;
	std::cout << "Attempting to access element 0 of empty array:" << std::endl;
	try
	{
		emptyArray[0] = 42;
	}
	catch (const std::out_of_range& e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "--------- Testing int array ---------" << std::endl;
	std::cout << std::endl;

	Array<int> array(5);
	std::cout << "Original int array:" << std::endl;
	for(unsigned int i = 0; i < array.size(); i++)
		std::cout << array[i] << std::endl;
	std::cout << "This array has " << array.size() << " elements." << std::endl;
	std::cout << std::endl;
	Array<int> deepCopy = array;
	std::cout << "Deep copy array:" << std::endl;
	for(unsigned int i = 0; i < deepCopy.size(); i++)
		std::cout << deepCopy[i] << std::endl;
	std::cout << "This array has " << deepCopy.size() << " elements." << std::endl;
	std::cout << std::endl;
	std::cout << "Altering deep copy..." << std::endl;
	for(unsigned int i = 0; i < deepCopy.size(); i++)
		deepCopy[i] = i;
	std::cout << "Deep copy after alteration:" << std::endl;
	for(unsigned int i = 0; i < deepCopy.size(); i++)
		std::cout << deepCopy[i] << std::endl;
	std::cout << std::endl;
	std::cout << "Original array after deep copy (unchanged):" << std::endl;
	for(unsigned int i = 0; i < array.size(); i++)
		std::cout << array[i] << std::endl;
	std::cout << std::endl;
	std::cout << "Testing original array out of bounds access:" << std::endl;
	try
	{
		array[10] = 42;
	}
	catch (const std::out_of_range& e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << "Testing deep copy array out of bounds access:" << std::endl;
	try
	{
		deepCopy[10] = 42;
	}
	catch (const std::out_of_range& e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "--------- Testing string array ---------" << std::endl;
	std::cout << std::endl;

	Array<std::string> strArray(3);
	strArray[0] = "Hello";
	strArray[1] = "World";
	strArray[2] = "!";

	std::cout << "Original string array:" << std::endl;
	for(unsigned int i = 0; i < strArray.size(); i++)
		std::cout << strArray[i] << std::endl;
	std::cout << "This array has " << strArray.size() << " elements." << std::endl;
	std::cout << std::endl;
	Array<std::string> stringDeepCopy = strArray;
	std::cout << "String deep copy array:" << std::endl;
	for(unsigned int i = 0; i < stringDeepCopy.size(); i++)
		std::cout << stringDeepCopy[i] << std::endl;
	std::cout << "This array has " << stringDeepCopy.size() << " elements." << std::endl;
	std::cout << std::endl;
	std::cout << "Altering deep copy..." << std::endl;
	for(unsigned int i = 0; i < stringDeepCopy.size(); i++)
		stringDeepCopy[i] = "Altered";
	std::cout << "Deep copy after alteration:" << std::endl;
	for(unsigned int i = 0; i < stringDeepCopy.size(); i++)
		std::cout << stringDeepCopy[i] << std::endl;
	std::cout << std::endl;
	std::cout << "Original array after deep copy (unchanged):" << std::endl;
	for(unsigned int i = 0; i < strArray.size(); i++)
		std::cout << strArray[i] << std::endl;
	std::cout << std::endl;
	std::cout << "Testing original string array out of bounds access:" << std::endl;
	try
	{
		strArray[10] = "42";
	}
	catch (const std::out_of_range& e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << "Testing string deep copy array out of bounds access:" << std::endl;
	try
	{
		stringDeepCopy[10] = "42";
	}
	catch (const std::out_of_range& e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--------- Testing assignment operator ---------" << std::endl;

	Array<int> array1(5);
	Array<int> array2(5);
	array1[0] = 1;
	array1[1] = 2;
	array1[2] = 3;
	array1[3] = 4;
	array1[4] = 5;

	std::cout << "Original array 1:" << std::endl;
	for (unsigned int i = 0; i < array1.size(); i++)
		std::cout << array1[i] << std::endl;
	std::cout << std::endl;

	std::cout << "Original array 2 (uninitialized):" << std::endl;
	for (unsigned int i = 0; i < array2.size(); i++)
		std::cout << array2[i] << std::endl;
	std::cout << std::endl;
	std::cout << "Assigning array 1 to array 2..." << std::endl;

	array2 = array1;

	std::cout << "Array 2 after assignment from array 1:" << std::endl;
	for (unsigned int i = 0; i < array2.size(); i++)
		std::cout << array2[i] << std::endl;

	return 0;
}
