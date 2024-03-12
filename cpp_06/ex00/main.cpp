#include "ScalarConverter.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "The only parameters mandatory are the ./Scaler 'an int, a char, a float or a double'!" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
}
