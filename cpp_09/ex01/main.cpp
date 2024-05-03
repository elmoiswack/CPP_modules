#include "RPN.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Error: only 1 argument needed, a sequence of single numbers and '+ - / *' chars.\nFor example: '1 2 * 2 * 2 -'!" << std::endl;
		return (1);
	}
	try
	{
		RPN prog;
		prog.CalculateNumb(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << "ERROR:" << e.what() << '\n';
	}
}