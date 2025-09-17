#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
	(void)other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	(void)other;
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::sortVector(std::vector<int>& vec)
{
	mergeInsertSort(vec);
}

void PmergeMe::sortDeque(std::deque<int>& deq)
{
	mergeInsertSort(deq);
}

void PmergeMe::parseInput(int argc, char **argv, std::vector<int>& vec, std::deque<int>& deq)
{
	for(int i = 1; i < argc; i++)
	{
		std::string arg = argv[i];

		// Check for empty argument
		if(arg.empty())
		{
			throw std::invalid_argument("Error: empty argument provided");
		}

		// Check for non-digit characters
		for(size_t j = 0; j < arg.size(); j++)
		{
			if(!std::isdigit(arg[j]))
			{
				throw std::invalid_argument("Error: '" + arg + "' contains non-digit characters");
			}
		}

		long num = std::atol(arg.c_str());

		// Check for negative numbers
		if (num < 0)
		{
			throw std::invalid_argument("Error: negative number '" + arg + "' is not allowed");
		}

		// Check for integer overflow
		if (num > INT_MAX)
		{
			throw std::invalid_argument("Error: number '" + arg + "' is too large (exceeds INT_MAX)");
		}

		vec.push_back(static_cast<int>(num));
		deq.push_back(static_cast<int>(num));
	}

	// Check minimum input requirement
	if(vec.empty())
	{
		throw std::invalid_argument("Error: no valid integers provided");
	}
}

void PmergeMe::printContainer(const std::vector<int>& container, const std::string& label)
{
	std::cout << label << ": ";
	for(size_t i = 0; i < container.size(); i++)
	{
		std::cout << container[i];
		if(i < container.size() - 1) std::cout << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printTimestamp(size_t size, const std::string& containerType, double time)
{
	std::cout << "Time to process a range of " << size
			  << " elements with " << containerType << " : " << time << " us" << std::endl;
}

std::vector<size_t> PmergeMe::generateJacobsthal(size_t n)
{
	std::vector<size_t> jacobsthal;
	if (n <= 1) return jacobsthal;

	// Generate Jacobsthal numbers
	std::vector<size_t> jnumbers;
	jnumbers.push_back(1);
	if (n > 1) jnumbers.push_back(1);

	while (jnumbers.back() < n)
	{
		size_t next = jnumbers[jnumbers.size()-1] + 2 * jnumbers[jnumbers.size()-2];
		jnumbers.push_back(next);
	}

	// Create insertion sequence based on Jacobsthal numbers
	std::vector<bool> used(n, false);

	for (size_t i = 1; i < jnumbers.size(); ++i)
	{
		size_t start = jnumbers[i] - 1;
		size_t end = (i > 1) ? jnumbers[i-1] - 1 : 0;

		for (size_t j = std::min(start, n-1); j > end && j < n; --j)
		{
			if (!used[j])
			{
				jacobsthal.push_back(j);
				used[j] = true;
			}
		}
	}

	return jacobsthal;
}
