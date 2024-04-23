#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	if (argc < 3)
	{
		std::cout << "ERROR: add more positive numbers to the sequence, minimum of 2 numbers!" << std::endl;
		return (1);
	}
	try
	{
		PmergeMe prog;
		prog.ParseNumbers(argv);
		prog.StartSort();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}