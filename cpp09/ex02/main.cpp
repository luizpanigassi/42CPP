#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << " <list of positive integers>" << std::endl;
		return 1;
	}

	try
	{
		PmergeMe sorter;
		std::vector<int> vec;
		std::deque<int> deq;

		sorter.parseInput(argc, argv, vec, deq);

		sorter.printContainer(vec, "Before");

		// Vector sorting
		clock_t start = clock();
		sorter.sortVector(vec);
		clock_t end = clock();
		double vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

		// Deque sorting
		start = clock();
		sorter.sortDeque(deq);
		end = clock();
		double dequeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

		sorter.printContainer(vec, "After");

		sorter.printTimestamp(vec.size(), "std::vector", vectorTime);
		sorter.printTimestamp(deq.size(), "std::deque", dequeTime);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
