#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal constructor is called and type is empty!" << std::endl;
	this->type = "Empty";
}

Animal::Animal(const Animal &in)
{
	std::cout << "Animal copy constructor is called!" << std::endl;
	*this = in;
}

Animal& Animal::operator=(const Animal &in)
{
	std::cout << "Animal '=' operator overload is called!" << std::endl;
	if (this == &in)
		return (*this);
	this->type = in.type;
	return (*this);
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