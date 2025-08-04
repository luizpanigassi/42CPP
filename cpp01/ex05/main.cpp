#include "Harl.hpp"

int main(int argc, char **argv)
{
	std::cout << std::endl;

	Harl harl;

	std::cout << std::endl;

	if (argc == 2)
	{
		std::string level = argv[1];
		std::cout << "Harl is going to complain about: " << level << std::endl;
		std::cout << std::endl;
		harl.complain(level);
	}
	else
	{
		std::cout << std::endl;
		std::cout << "Usage: " << argv[0] << " <complaint level>" << std::endl;
		std::cout << std::endl;
		std::cout << "Available levels: DEBUG, INFO, WARNING, ERROR" << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;


	return 0;
}
