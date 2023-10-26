#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal constructor is called and type is empty!" << std::endl;
	this->type = "Empty";
}

Animal::~Animal()
{
	std::cout << "Animal deconstructor is called!" << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "Animal noises..." << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}