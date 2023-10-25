#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal constructor is called and type is empty!" << std::endl;
	this->type = "Empty";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal deconstructor is called!" << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal noises..." << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}