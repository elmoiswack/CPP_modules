#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor is called and type is set!" << std::endl;
	this->type = "Dog";
}

Dog::~Dog()
{
	std::cout << "Dog deconstructor is called!" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Woef woef" << std::endl;
}

const std::string	Dog::getType() const
{
	return (this->type);
}