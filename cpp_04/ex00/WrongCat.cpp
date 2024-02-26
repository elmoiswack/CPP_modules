#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat constructor is called and type is set" << std::endl;
	this->type = "WrongCat";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat deconstructor is called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &in)
{
	std::cout << "WrongCat copy constructor is called!" << std::endl;
	*this = in;
}

WrongCat& WrongCat::operator=(const WrongCat &in)
{
	std::cout << "WrongCat '=' operator overload is called!" << std::endl;
	if (this == &in)
		return (*this);
	this->type = in.type;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "WUUAAIM" << std::endl; 
}

std::string	WrongCat::getType() const
{
	return (this->type);
}