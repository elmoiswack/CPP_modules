#include "Harl.hpp"

int	main(void)
{
	Harl harler;

	std::cout << "Harl DEBUG" << std::endl;
	harler.complain("debug");
	std::cout << std::endl;

	std::cout << "Harl INFO" << std::endl;
	harler.complain("info");
	std::cout << std::endl;

		std::cout << "Harl warning" << std::endl;
	harler.complain("warning");
	std::cout << std::endl;

	std::cout << "Harl ERROR" << std::endl;
	harler.complain("error");
	std::cout << std::endl;

	std::cout << "Harl RANDOM" << std::endl;
	harler.complain("random");
	std::cout << std::endl;

	return (0);
}