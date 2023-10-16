#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &club) : weapons(club)
{
	std::cout << "Constructor Human A is used!" << std::endl;
	this->name = name;
	this->weapons = club;
}

HumanA::~HumanA()
{
	std::cout << "Deconstructor Human A is used!" << std::endl;
}

void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with their " << this->weapons.getType() << std::endl;
}