#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor is called, type is set and it's brain is allocated!" << std::endl;
	this->type = "Dog";
	this->dogBrain = new Brain();
}

Dog::Dog(const Dog &in)
{
	std::cout << "Dog copy constructor is called!" << std::endl;
	this->dogBrain = NULL;
	*this = in;
}

Dog& Dog::operator=(const Dog &in)
{
	std::cout << "Dog '=' operator overload is called!" << std::endl;
	if (this == &in)
		return (*this);
	this->type = in.type;
	delete this->dogBrain;
	this->dogBrain = new Brain(*in.dogBrain);
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog deconstructor is called!" << std::endl;
	delete this->dogBrain;
	std::cout << "Dogs brain is deleted, it's brainless!" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Woef woef" << std::endl;
}

const std::string	Dog::getType() const
{
	return (this->type);
}