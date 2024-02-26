#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor is called, type is set" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &in)
{
	std::cout << "Cat copy constructor is called!" << std::endl;
	*this = in;
}

Cat& Cat::operator=(const Cat &in)
{
	std::cout << "Cat '=' operator overload is called!" << std::endl;
	if (this == &in)
		return (*this);
	this->type = in.type;
	return (*this);
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