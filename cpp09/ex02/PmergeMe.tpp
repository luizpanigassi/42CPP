template<typename Container>
void PmergeMe::mergeInsertSort(Container& c)
{
	if (c.size() <= 1) return;

	// Create pairs and sort
	std::vector<std::pair<int, int> > pairs;
	bool hasOdd = false;
	int oddElement = 0;

	// Create pairs
	for (size_t i = 0; i < c.size(); i += 2)
	{
		if (i + 1 < c.size()) {
			int a = c[i];
			int b = c[i + 1];
			if (a > b) std::swap(a, b);
			pairs.push_back(std::make_pair(a, b)); // smaller, larger
		}
		else
		{
			hasOdd = true;
			oddElement = c[i];
		}
	}

	if (pairs.empty())
	{
		if (hasOdd) {
			c.clear();
			c.push_back(oddElement);
		}
		return;
	}

	// Sort larger elements using recursion
	Container largerElements;
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		largerElements.push_back(pairs[i].second);
	}

	mergeInsertSort(largerElements);

	// Create main container with larger elements
	Container mainChain = largerElements;

	// Insert smaller elements using Jacobsthal
	std::vector<int> smallerElements;
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		smallerElements.push_back(pairs[i].first);
	}

	// Insert first smaller element at beginning
	if (!smallerElements.empty())
	{
		mainChain.insert(mainChain.begin(), smallerElements[0]);
	}

	// Generate Jacobsthal numbers for insertion order
	std::vector<size_t> jacobsthal = generateJacobsthal(smallerElements.size());

	// Insert remaining smaller elements in Jacobsthal order
	std::vector<bool> inserted(smallerElements.size(), false);

	if (!smallerElements.empty())
		inserted[0] = true;

	for (size_t i = 0; i < jacobsthal.size(); ++i)
	{
		size_t idx = jacobsthal[i];
		if (idx < smallerElements.size() && !inserted[idx])
		{
			binaryInsertIntoChain(mainChain, smallerElements[idx]);
			inserted[idx] = true;
		}
	}

	// Insert any remaining elements
	for (size_t i = 0; i < smallerElements.size(); ++i)
	{
		if (!inserted[i])
		{
			binaryInsertIntoChain(mainChain, smallerElements[i]);
		}
	}

	// Insert odd element if exists
	if (hasOdd)
	{
		binaryInsertIntoChain(mainChain, oddElement);
	}

	c = mainChain;
}

template<typename Container>
void PmergeMe::binaryInsertIntoChain(Container& chain, int value)
{
	typename Container::iterator pos = std::lower_bound(chain.begin(), chain.end(), value);
	chain.insert(pos, value);
}
