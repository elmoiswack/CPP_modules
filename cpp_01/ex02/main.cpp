#include <iostream>

int	main(void)
{
	std::string brain = "HI THIS IS BRAIN";
	std::string 	*stringPTR = &brain;
	std::string&	stringREF = brain;

	std::cout << "Memory adress:" << std::endl;
	std::cout << "brain = " << &brain << std::endl;
	std::cout << "stringPTR = " << &stringPTR << std::endl;
	std::cout << "stringREF = " << &stringREF << std::endl;

	std::cout << "" << std::endl;
	std::cout << "Value:" << std::endl;
	std::cout << "brain = " << brain << std::endl;
	std::cout << "stringPTR = " << *stringPTR << std::endl;
	std::cout << "stringREF = " << stringREF << std::endl;


}