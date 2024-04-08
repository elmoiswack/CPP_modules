#include "BitcoinExchange.hpp"
#include <fstream>

BitcoinExchange::BitcoinExchange()
{
	std::cout << "Default deconstructor is called!" << std::endl;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "Default deconstructor is called!" << std::endl;
}

void BitcoinExchange::FilesParser(char *arg)
{
	std::ifstream FdInput;
	std::ifstream FdDatabase;

	FdInput.open(arg);
	FdDatabase.open("./data.csv");

}