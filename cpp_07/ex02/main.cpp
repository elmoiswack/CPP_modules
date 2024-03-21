#include "Array.hpp"

int	main(void)
{
	Array<int> arr(8);
	std::cout << std::endl;
	srand(time(NULL));
	for (int i = 0; i < arr.size(); i++)
	{
		arr[i] = rand() % 100;
	}
	Array<int> bruh(arr);
	std::cout << std::endl;

	for (int i = 0; i < arr.size(); i++)
	{
		std::cout << "arr["<< i << "] = "<< arr[i];
		std::cout << " bruh["<< i << "] = "<< bruh[i] << std::endl;
	}
	std::cout << std::endl;

	Array<std::string> herb(5);
	std::cout << std::endl;
	herb[0] = "hallo";
	herb[1] = "my";
	herb[2] = "name";
	herb[3] = "is";
	herb[4] = "dante";

	Array<std::string> nani(herb);
	std::cout << std::endl;
	for (int j = 0; j < herb.size(); j++)
	{
		std::cout << "herb["<< j << "] = "<< herb[j];
		std::cout << " nani["<< j << "] = "<< nani[j] << std::endl;
	}
	std::cout << std::endl;
	try
	{
		arr[32] = 4;
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception caught!!" << std::endl;
		std::cerr << e.what() << '\n';
	}
		try
	{
		herb[-2] = "bla bla";
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception caught!!" << std::endl;
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
}