#include "iter.hpp"

template <typename T>
void	intchar_ft(T input)
{
	if (input >= 32 && input <= 126)
		std::cout << "The ascii value is printable!" << std::endl;
	else
		std::cout << "Not a printable ascii value!" << std::endl;
}

template <typename T>
void	str_test(T input)
{
	for (int i = 0; input[i]; i++)
	{
		std::cout << input[i];
	}
	std::cout << std::endl;
}

int	main(void)
{
	const int arr[] = {4, 76, 42432};
	iter(arr, 3, intchar_ft<const int &>);
	std::cout << std::endl;
	
	const char bruh[] = {'f', '3', 'h', 12};
	iter(bruh, 4, intchar_ft<const char &>);
	std::cout << std::endl;
	
	std::string nani[] = {"Chad", "Brad", "brother"};
	iter(nani, 3, str_test<std::string &>);
	std::cout << std::endl;

	const char *last[] = {"Nicole", "Patricia", "sister"};
	iter(last, 3, str_test<const char *>);
	std::cout << std::endl;
}