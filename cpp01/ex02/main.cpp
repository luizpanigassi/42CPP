#include <iostream>
#include <string>

int main()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string* stringPTR = &brain;
	std::string& stringREF = brain;

	std::cout << "===== First, let's look at memory addresses: ======" << std::endl;
	std::cout << "This is the memory address of brain: " << &brain << std::endl;
	std::cout << "This is the address held by the pointer: " << stringPTR << std::endl;
	std::cout << "This is the address held by the reference: " << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "===== Now, let's look at the values: ======" << std::endl;
	std::cout << "This is the value of brain: " << brain << std::endl;
	std::cout << "This is the value pointed to by the pointer: " << *stringPTR << std::endl;
	std::cout << "This is the value pointed to by the reference: " << stringREF << std::endl;

	return 0;
}
