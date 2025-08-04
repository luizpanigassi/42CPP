#include "Sed.hpp"

int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		std::cout << "Usage: " << argv[0] << " <filename> <string to find> <string to replace>" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	Sed sed(filename, s1, s2);
	if (!sed.replace())
	{
		std::cerr << "Something went wrong during the replacement process." << std::endl;
		return 1;
	}

	std::cout << "Process finished!" << std::endl;
	return 0;
}
