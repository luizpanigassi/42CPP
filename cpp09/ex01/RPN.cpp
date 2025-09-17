#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) {
	(void)other;
}

RPN& RPN::operator=(const RPN& other)
{
	(void)other;
	return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string& token) const
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

int RPN::applyOperation(int a, int b, const std::string& op) const
{
	if (op == "+") return a + b;
	if (op == "-") return a - b;
	if (op == "*") return a * b;
	if (op == "/")
	{
		if (b == 0)
			throw std::runtime_error("Error: Division by zero!");
		return a / b;
	}
	throw std::runtime_error("Error: Unknown operator!");
}

int RPN::evaluate(const std::string& expression)
{
	std::stack<int> stack;
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
	{
		if (isOperator(token))
		{
			if (stack.size() < 2)
				throw std::runtime_error("Error: not enough operands before operator '" + token + "'.");

			int right = stack.top(); stack.pop();
			int left = stack.top(); stack.pop();

			int result = applyOperation(left, right, token);
			stack.push(result);
		}
		else
		{
			char* endptr;
			long num = std::strtol(token.c_str(), &endptr, 10);

			if (*endptr != '\0' || endptr == token.c_str())
				throw std::runtime_error("Error: invalid token '" + token + "' — expected a number or operator.");

			if (num > INT_MAX || num < INT_MIN)
				throw std::runtime_error("Error: number out of range '" + token + "'.");

			stack.push(static_cast<int>(num));
		}
	}

	if (stack.size() != 1)
		throw std::runtime_error("Error: expression could not be fully reduced — check operators/operands.");

	return stack.top();
}
