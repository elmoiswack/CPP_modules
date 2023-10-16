#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	std::cout << "Constructor Human B is used!" << std::endl;
	this->name = name;
	this->weapons = NULL;
}

HumanB::~HumanB()
{
	std::cout << "Deconstructor Humand B is used!" << std::endl;
}

void	HumanB::attack()
{
	std::cout << this->name << " attacks with their " << this->weapons->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &club)
{
	this->weapons = &club;
}