#include <easyfind.hpp>

int main()
{
	std::vector<int> vec;
	for(int i = 0; i < 10; i++)
		vec.push_back(i * 2);

	std::cout << std::endl;
	std::cout << "Vector contents: " << std::endl;
	for(size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Trying to find a 6 in the container..." << std::endl;
	try
	{
		std::vector<int>::iterator it = easyfind(vec, 6);
		std::cout << "Value found: " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << "Trying to find a 200 in the container..." << std::endl;

	try
	{
		std::vector<int>::iterator it = easyfind(vec, 200);
		std::cout << "Value found: " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	return 0;
}
