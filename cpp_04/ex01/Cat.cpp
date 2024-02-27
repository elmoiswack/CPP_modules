#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor is called, type is set and brain is allocated!" << std::endl;
	this->type = "Cat";
	this->catBrain = new Brain();
}

Cat::Cat(const Cat &in)
{
	std::cout << "Cat copy constructor is called!" << std::endl;
	std::cout << "Adress of in.catBrain = " << &in.catBrain << std::endl;
	this->catBrain = NULL;
	*this = in;
	std::cout << "Adress of this->catBrain = " << &this->catBrain << std::endl;
}

Cat& Cat::operator=(const Cat &in)
{
	std::cout << "Cat '=' operator overload is called!" << std::endl;
	if (this == &in)
		return (*this);
	this->type = in.type;
	delete this->catBrain;
	this->catBrain = new Brain(*in.catBrain);
	return (*this);
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