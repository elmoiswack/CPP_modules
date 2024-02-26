#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor is called and type is set!" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &in)
{
	std::cout << "Dog copy constructor is called!" << std::endl;
	*this = in;
}

Dog& Dog::operator=(const Dog &in)
{
	std::cout << "Dog '=' operator overload is called!" << std::endl;
	if (this == &in)
		return (*this);
	this->type = in.type;
	return (*this);
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