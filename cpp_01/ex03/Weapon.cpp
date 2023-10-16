#include "Weapon.hpp"

Weapon::Weapon(std::string newtype)
{
	std::cout << "Weapon constructor is used!" << std::endl;
	this->setType(newtype);
}

Weapon::~Weapon()
{
	std::cout << "Deconstrustor Weapon is used!" << std::endl;
}

const std::string& Weapon::getType(void)
{
	const std::string& reference = this->type;
	return (reference);
}

void	Weapon::setType(std::string newtype)
{
	std::cout << "New weapon is set!" << std::endl;
	this->type = newtype;
}