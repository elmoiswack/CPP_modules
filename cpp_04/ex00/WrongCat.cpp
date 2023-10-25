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

void	WrongCat::makeSound() const
{
	std::cout << "WUUAAIM" << std::endl; 
}

std::string	WrongCat::getType() const
{
	return (this->type);
}