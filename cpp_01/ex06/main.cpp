#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	Harl harler;

	if (argc != 2)
	{
		std::cout << "Program takes 1 argument besides the program name!"<< std::endl;
		return (-1);
	}
	harler.complain(argv[1]);
	return (0);
}