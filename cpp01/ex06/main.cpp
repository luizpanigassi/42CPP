#include "Harl.hpp"

int get_index(const std::string& level)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
			return i;
	}
	return -1;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: " << argv[0] << " <complaint level>" << std::endl;
		std::cout << "Available levels: DEBUG, INFO, WARNING, ERROR" << std::endl;
		return 1;
	}
	std::string level = argv[1];
	Harl harl;
	int index = get_index(level);

	switch (index)
	{
		case 0:
			harl.debug();
		case 1:
			harl.info();
		case 2:
			harl.warning();
		case 3:
			harl.error();
			break;
		default:
			std::cout << "Harl seems... content. That's weird. You'd better hide." << std::endl;
	}
	return 0;
}
