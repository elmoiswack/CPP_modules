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
	std::cout << "Brain deconstructor is called!!" << std::endl;
}

Brain::Brain(const Brain &in)
{
    std::cout << "Brain copy constructor is called!" << std::endl;
    for (int i = 0; i < 100; i++)
    {
        std::cout << in.ideas[i] << std::endl;
    }
    *this = in;
    for (int i = 0; i < 100; i++)
    {
        std::cout << this->ideas[i] << std::endl;
    }
    return;
}

Brain& Brain::operator=(const Brain& in)
{
    std::cout << "Brain '=' operator overload is called!" << std::endl;
    if (this != &in)
    {
        for (int i = 0; i < 100; i++)
        {
            this->ideas[i] = in.ideas[i];
        }
    }
    return (*this);
}