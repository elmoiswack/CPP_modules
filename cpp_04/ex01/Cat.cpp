#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor is called and type is set!" << std::endl;
	this->type = "Cat";
}

Cat::~Cat()
{
	std::cout << "Cat deconstructor is called!" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Miauuuwww" << std::endl;
}

std::string	Cat::getType() const
{
	return (this->type);
}