#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <cctype>

class BitcoinExchange {
public:
	// Constructors and Destructor
	BitcoinExchange(const std::string& filename);
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	float getRate(const std::string& date); // Get the exchange rate for a given date
	bool loadData(const std::string& filename); // To load the CSV file
	bool checkOnlySpaces(std::string& line); // Check if line is only spaces
	bool checkDate(const std::string& date); // Check valid date
	bool checkValue(float value); // Check valid value

private:
	std::map<std::string, float> data; // Map with key/value pair date/price
};

// Reader
void readInputFile(const char *inputFile, BitcoinExchange& btc); // Read the input file and process each line

// Checkers
bool checkInputFile(std::string& inputLine, BitcoinExchange& btc); // Check valid input line

// Getters
int getCurrentYear(); // Get the current year for reference

// Printer
void printFormat(std::string date, float value, BitcoinExchange& btc); // Print the output in the required format

#endif
