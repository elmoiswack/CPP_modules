#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Error: the only valid agruments are: ./btc 'the input file'" << std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange prog;
		prog.ConvertionData(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}