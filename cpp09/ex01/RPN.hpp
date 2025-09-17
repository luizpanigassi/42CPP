#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <stdexcept>
#include <string>
#include <cctype>
#include <climits>
#include <cstdlib>

class RPN {
public:
	// Constructors and Destructor
	RPN();
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	~RPN();

	int evaluate(const std::string& expression);
	bool isOperator(const std::string& token) const;
	int applyOperation(int a, int b, const std::string& op) const;

private:
};

#endif
