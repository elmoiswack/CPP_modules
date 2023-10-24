#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name)
{
	std::cout << "FragTrap constructor is called and name is set!" << std::endl;
	this->name = name;
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap deconstructor is called!" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "Come on, I know you want to give me a high-five!" << std::endl;
}