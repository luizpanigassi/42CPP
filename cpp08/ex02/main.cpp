#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;

	std::cout << std::endl;
	mstack.push(5);
	mstack.push(11);
	std::cout << "Stack size: " << mstack.size() << std::endl;
	std::cout <<  "Top element: " << mstack.top() << std::endl;
	std::cout << std::endl;

	std::cout << "Stack elements:" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	mstack.pop();
	std::cout << std::endl;

	std::cout << "Stack size after pop: " << mstack.size() << std::endl;
	std::cout << "Stack elements after pop:" << std::endl;
	it = mstack.begin();
	ite = mstack.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	mstack.push(10);
	mstack.push(22);
	mstack.push(399);
	mstack.push(100);
	mstack.push(76);
	mstack.push(47);
	std::cout << std::endl;
	std::cout << "Stack size after pushing more elements: " << mstack.size() << std::endl;
	std::cout << "Stack elements:" << std::endl;
	it = mstack.begin();
	ite = mstack.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	return 0;
}
