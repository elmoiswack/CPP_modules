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

WrongAnimal::WrongAnimal(const WrongAnimal &in)
{
	std::cout << "WrongAnimal copy constructor is called!" << std::endl;
	*this = in;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &in)
{
	std::cout << "WrongAnimal '=' operator overload is called!" << std::endl;
	if (this == &in)
		return (*this);
	this->type = in.type;
	return (*this);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal noises..." << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}