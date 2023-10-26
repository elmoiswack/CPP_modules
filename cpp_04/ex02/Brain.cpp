#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor is called!" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = "Bruh moment";
	}
}

Brain::~Brain()
{
	std::cout << "Brain deconstructor is called" << std::endl;
}