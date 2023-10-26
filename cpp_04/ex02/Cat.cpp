#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor is called, type is set and brain is allocated!" << std::endl;
	this->type = "Cat";
	this->catBrain = new Brain();
}

Cat::~Cat()
{
	std::cout << "Cat deconstructor is called!" << std::endl;
	delete this->catBrain;
	std::cout << "Cats brain is deleted, it's brainless!" << std::endl; 
}

void	Cat::makeSound() const
{
	std::cout << "Miauuuwww" << std::endl;
}

std::string	Cat::getType() const
{
	return (this->type);
}