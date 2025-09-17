#include "BitcoinExchange.hpp"

// Constructors and Destructor
BitcoinExchange::BitcoinExchange(const std::string& filename){
	loadData(filename);
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	this->data = other.data;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if(this != &other)
		this->data = other.data;
	return *this;
}

BitcoinExchange::~BitcoinExchange(){}

bool BitcoinExchange::loadData(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if(!file.is_open())
	{
		std::cerr << "Error: could not open file " << filename << std::endl;
		return false;
	}
	std::string line;
	std::getline(file, line);
	while(std::getline(file, line))
	{
		line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
		size_t pos = line.find(',');
		if(pos == std::string::npos)
			throw std::runtime_error("Data format invalid in file");
		std::string date = line.substr(0, pos);
		std::string rateStr = line.substr(pos + 1);
		float rate = std::atof(rateStr.c_str());
		this->data[date] = rate;
	}
	return true;
}

float BitcoinExchange::getRate(const std::string& date)
{
	std::map<std::string, float>::iterator it = this->data.lower_bound(date);
	if(it != this->data.end() && it->first == date)
		return it->second;
	if(it == this->data.begin())
		throw std::runtime_error("No data available for the given date or earlier");
	--it;
	return it->second;
}

void readInputFile(const char *inputFile, BitcoinExchange& btc)
{
	std::ifstream file(inputFile);
	if(!file.is_open())
	{
		std::cerr << "Error: could not open input file " << inputFile << std::endl;
		return;
	}
	if(file.peek() == EOF)
	{
		std::cerr << "Error: input file is empty" << std::endl;
		return;
	}
	std::string inputLine;
	std::getline(file, inputLine);
	if(inputLine != "date | value")
	{
		std::cerr << "Error: invalid header format in input file" << std::endl;
		return;
	}
	while(std::getline(file, inputLine))
		checkInputFile(inputLine, btc);
}

bool checkInputFile(std::string& inputLine, BitcoinExchange& btc)
{
	inputLine.erase(std::remove(inputLine.begin(), inputLine.end(), ' '), inputLine.end());
	if(inputLine.empty() || btc.checkOnlySpaces(inputLine))
	{
		std::cerr << "Error: line is empty or only spaces" << std::endl;
		return false;
	}
	size_t pos = inputLine.find('|');
	if(pos == inputLine.npos)
	{
		std::cerr << "Error: invalid format, missing a '|' character" << std::endl;
		return false;
	}
	if (inputLine.find('|', pos + 1) != inputLine.npos)
	{
		std::cerr << "Error: invalid format, multiple '|' found" << std::endl;
		return false;
	}
	std::string date = inputLine.substr(0, pos);
	std::string value = inputLine.substr(pos + 1);
	float floatValue = std::atof(value.c_str());
	if(!btc.checkDate(date))
	{
		std::cerr << "Error: invalid date => " << date << std::endl;
		return false;
	}
	if(!btc.checkValue(floatValue))
	{
		std::cerr << "Error: invalid value => " << value << std::endl;
		return false;
	}
	printFormat(date, floatValue, btc);
	return true;
}

bool BitcoinExchange::checkDate(const std::string& date)
{
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	int currentYear = getCurrentYear();
	if(month < 1 || month > 12)
		return false;
	if((day < 1 || day > 31) || (month == 2 && day > 29))
		return false;
	if (year > currentYear)
		return false;
	if(month == 4 || month == 6 || month == 9 || month == 11)
	{
		if(day > 30)
			return false;
	}
	return true;
}

bool BitcoinExchange::checkValue(float value)
{
	if(value < 0)
	{
		std::cerr << "Error: value can't be negative." << std::endl;
		return false;
	}
	if(value > 1000)
	{
		std::cerr << "Error: value too large." << std::endl;
		return false;
	}
	return true;
}

bool BitcoinExchange::checkOnlySpaces(std::string& line)
{
	for(size_t i = 0; i < line.size(); i++)
	{
		if(!std::isspace(line[i]))
			return false;
	}
	return true;
}

int getCurrentYear()
{
	time_t now = time(0);
	int currentYear = 1900 + localtime(&now)->tm_year;
	return currentYear;
}

void printFormat(std::string date, float value, BitcoinExchange& btc)
{
	std::cout << date << " => " << value << " = " << btc.getRate(date) * value << std::endl;
}
