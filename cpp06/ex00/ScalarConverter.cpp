#include "ScalarConverter.hpp"

// Constructors/Destructor
ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter(){}

// Helpers
static bool isChar(const std::string& literal)
{
	return (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]));
}

static bool isInt(const std::string& literal)
{
	size_t i = 0;
	if (literal[i] == '-' || literal[i] == '+')
		i++;
	for (; i < literal.length(); i++)
	{
		if (!std::isdigit(literal[i]))
			return false;
	}
	return true;
}

static bool isDouble(const std::string& literal)
{
	size_t i = 0;
	bool hasDecimal = false;
	bool hasDigit = false;

	if(literal[i] == '-' || literal[i] == '+')
		i++;

	for(; i < literal.length(); i++)
	{
		if(literal[i] == '.')
		{
			if(hasDecimal) return false;
			hasDecimal = true;
		}
		else if(std::isdigit(literal[i]))
			hasDigit = true;
		else
		{
			return false;
		}
	}
	return hasDecimal && hasDigit;
}

static bool isFloat(const std::string& literal)
{
	if (literal.empty() || literal[literal.length() - 1] != 'f')
		return false;

	std::string core = literal.substr(0, literal.length() - 1);
	return isDouble(core);
}

static bool isPseudoLiteral(const std::string& literal)
{
	return (literal == "nan" || literal == "nanf" || literal == "+inf" ||
			literal == "-inf" || literal == "+inff" || literal == "-inff");
}

// Converter helpers
static void errorConverting()
{
	std::cout << "char: " << RED << "impossible" << RESET << std::endl;
	std::cout << "int: " << RED << "impossible" << RESET << std::endl;
	std::cout << "float: " << RED << "impossible" << RESET << std::endl;
	std::cout << "double: " << RED << "impossible" << RESET << std::endl;
	return;
}

static void convertChar(const std::string& literal)
{
	std::cout << "char: " << GREEN << "'" << literal[0] << "'" << RESET << std::endl;
	std::cout << "int: " << GREEN << static_cast<int>(literal[0]) << RESET << std::endl;
	std::cout << "float: " << GREEN << static_cast<float>(literal[0]) << "f" << RESET << std::endl;
	std::cout << "double: " << GREEN << static_cast<double>(literal[0]) << RESET << std::endl;
	return;
}

static void convertInt(const std::string& literal)
{
	long long tmp;
	std::stringstream ss(literal);
	ss >> tmp;

	if (ss.fail() || !ss.eof() || tmp > INT_MAX || tmp < INT_MIN)
	{
		errorConverting();
		return;
	}

	int value = static_cast<int>(tmp);
	if (literal.length() == 1 && std::isdigit(literal[0])) {
		std::cout << "char: '" << GREEN << literal[0] << RESET << "'" << std::endl;
	} else {
		std::cout << "char: " << GREEN
				  << (std::isprint(value) ? "'" + std::string(1, static_cast<char>(value)) + "'" : "Non displayable")
				  << RESET << std::endl;
	}

	std::cout << "int: " << GREEN << value << RESET << std::endl;
	std::cout << "float: " << GREEN << static_cast<float>(value) << "f" << RESET << std::endl;
	std::cout << "double: " << GREEN << static_cast<double>(value) << RESET << std::endl;
}


static void convertFloat(const std::string& literal)
{
	std::string core = literal.substr(0, literal.length() - 1);
	float value;
	std::stringstream ss(core);
	ss >> value;
	if(ss.fail() || !ss.eof())
		errorConverting();

	std::cout << "char: " << GREEN << (std::isprint(static_cast<int>(value)) ? "'" + std::string(1, static_cast<char>(value)) + "'" : "Non displayable") << RESET << std::endl;
	std::cout << "int: " << GREEN << static_cast<int>(value) << RESET << std::endl;
	std::cout << "float: " << GREEN << value << "f" << RESET << std::endl;
	std::cout << "double: " << GREEN << static_cast<double>(value) << RESET << std::endl;
	return;
}

static void convertDouble(const std::string& literal)
{
	double value;
	std::stringstream ss(literal);
	ss >> value;
	if(ss.fail() || !ss.eof())
		errorConverting();

	std::cout << "char: " << GREEN << (std::isprint(static_cast<int>(value)) ? "'" + std::string(1, static_cast<char>(value)) + "'" : "Non displayable") << RESET << std::endl;
	std::cout << "int: " << GREEN << static_cast<int>(value) << RESET << std::endl;
	std::cout << "float: " << GREEN << static_cast<float>(value) << "f" << RESET << std::endl;
	std::cout << "double: " << GREEN << value << RESET << std::endl;
	return;
}

static void convertPseudoLiteral(const std::string& literal)
{
	std::cout << "char: " << RED << "impossible" << RESET << std::endl;
	std::cout << "int: " << RED << "impossible" << RESET << std::endl;
	if (literal[literal.length() - 1] == 'f')
	{
		std::cout << "float: " << GREEN << literal << RESET << std::endl;
		std::cout << "double: " << GREEN << literal.substr(0, literal.length() - 1) << RESET << std::endl;
	}
	else
	{
		std::cout << "float: " << GREEN << literal << "f" << RESET << std::endl;
		std::cout << "double: " << GREEN << literal << RESET << std::endl;
	}
	return;
}

// Converter

void ScalarConverter::convert(const std::string& literal)
{
	std::cout << std::fixed << std::setprecision(1);
	if (literal.empty())
	{
		std::cout << RED << "Error: no number detected!" << RESET << std::endl;
		return;
	}

	else if (isPseudoLiteral(literal))
	{
		convertPseudoLiteral(literal);
		return;
	}

	else if(isChar(literal))
	{
		convertChar(literal);
		return;
	}

	else if(isInt(literal))
	{
		convertInt(literal);
		return;
	}

	else if(isFloat(literal))
	{
		convertFloat(literal);
		return;
	}

	else if(isDouble(literal))
	{
		convertDouble(literal);
		return;
	}

	else
	{
		std::cout << RED << "Error: invalid input!" << RESET << std::endl;
		errorConverting();
	}
}
