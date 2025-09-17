#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <stdexcept>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <climits>

class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	void sortVector(std::vector<int>& vec);
	void sortDeque(std::deque<int>& deq);

	// Helper functions
	void parseInput(int argc, char **argv, std::vector<int>& vec, std::deque<int>& deq);
	void printContainer(const std::vector<int>& container, const std::string& label);
	void printTimestamp(size_t size, const std::string& containerType, double time);

	// Non-template helper function
	std::vector<size_t> generateJacobsthal(size_t n);

	// Template function declarations
	template<typename Container>
	void mergeInsertSort(Container& c);

	template<typename Container>
	void merge(Container& left, Container& right, Container& result);

	template<typename Container>
	void insertionSort(Container& c);

	template<typename Container>
	void binaryInsert(Container& c, int value);

	template<typename Container>
	void binaryInsertIntoChain(Container& chain, int value);
};

// Templates
#include "PmergeMe.tpp"

#endif
