#include "Zombie.hpp"

void	Zombie::setName(std::string name)
{
	std::cout << "Name is set" << std::endl;
	this->name = name;
}

Zombie::Zombie(void)
{
	std::cout << "Default constructor is used!" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->name << " is being destroyed!" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}