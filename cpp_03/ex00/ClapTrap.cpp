#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Default constructor is called and name is set!" << std::endl;
	this->_name = name;
	this->_attack_damage = 0;
	this->_hit_points = 10;
	this->_energy_points = 10;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Default deconstructor is called!" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_energy_points == 0)
	{
		std::cout << "This Claptrap has no energy points left" << std::endl;
		return ;
	}
	this->_energy_points -= 1;
	std::cout << "Claptrap: " << this->_name << " is charging towards " << target << ", dealing " << this->_attack_damage << " points of damage" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "Claptrap: " << this->_name << " has taken " << amount << " points of damage!" << std::endl;
	this->_hit_points -= amount;
	std::cout << "Claptrap: " << this->_name << " still has " << this->_hit_points << " ammount of hit points left!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_points == 0)
	{
		std::cout << "This Claptrap has no energy points left" << std::endl;
		return ;
	}
	this->_energy_points -= 1;
	this->_hit_points += amount;
	std::cout << "Claptrap: " << this->_name << " still has " << this->_hit_points << " ammount of hit points left!" << std::endl;
}