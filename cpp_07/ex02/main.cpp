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

// #include <iostream>
// #include "Array.hpp"

// #define MAX_VAL 10
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }