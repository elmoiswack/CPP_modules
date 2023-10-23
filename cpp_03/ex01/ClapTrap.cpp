#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Default constructor is called and name is set!" << std::endl;
	this->name = name;
	this->attack_damage = 0;
	this->hit_points = 10;
	this->energy_points = 10;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Default deconstructor is called!" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->energy_points == 0)
	{
		std::cout << "This Claptrap has no energy points left" << std::endl;
		return ;
	}
	this->energy_points -= 1;
	std::cout << "Claptrap: " << this->name << " is charging towards " << target << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "Claptrap: " << this->name << " has taken " << amount << " points of damage!" << std::endl;
	this->hit_points -= amount;
	std::cout << "Claptrap: " << this->name << " still has " << this->hit_points << " ammount of hit points left!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy_points == 0)
	{
		std::cout << "This Claptrap has no energy points left" << std::endl;
		return ;
	}
	this->energy_points -= 1;
	this->hit_points += amount;
	std::cout << "Claptrap: " << this->name << " still has " << this->hit_points << " ammount of hit points left!" << std::endl;
}