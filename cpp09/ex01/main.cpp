#include "RPN.hpp"

int main(int argc, char **argv)
{
	if(argc != 2)
		{
			std::cerr << "How to use: ./rpn \"<expression>\"" << std::endl;
			std::cout << "Example: ./rpn \"3 4 + 2 * 7 /\"" << std::endl;
			return 1;
		}

	RPN rpn;
	try
	{
		int result = rpn.evaluate(argv[1]);
		std::cout << "Final result: " << result << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
