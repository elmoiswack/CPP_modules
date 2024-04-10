#include "easyfind.hpp"
#include <vector>

const char* IntNotFoundException::what() const throw()
{
	return ("The interger value you are trying to find in the container isn't inside the container!!");
}

int	main(void)
{
	std::vector<int> arr = {1, 43, 32, 754, 12, 11};

	try
	{
		easyfind(arr, 32);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		easyfind(arr, 13);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}