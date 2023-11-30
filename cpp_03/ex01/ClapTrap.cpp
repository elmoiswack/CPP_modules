#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap constructor is called and name is set!" << std::endl;
	this->name = name;
	this->attack_damage = 0;
	this->hit_points = 10;
	this->energy_points = 10;
}

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor without name is called!" << std::endl;
	this->name = "Empty";
	this->attack_damage = 0;
	this->hit_points = 10;
	this->energy_points = 10;
}

ClapTrap::~ClapTrap()
{
	std::cout << "CLaptrap deconstructor is called!" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->energy_points <= 0)
	{
		std::cout << "Claptrap " << this->name << " has no energy points left" << std::endl;
		return ;
	}
	if (this->hit_points <= 0)
	{
		std::cout << "Claptrap " << this->name << " is dead!" << std::endl;
		return ;
	}
	this->energy_points -= 1;
	std::cout << "Claptrap: " << this->name << " is charging towards " << target << ", dealing " << this->attack_damage << " ammount of damage" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "Claptrap: " << this->name << " has taken " << amount << " points of damage!" << std::endl;
	this->hit_points -= amount;
	std::cout << "Claptrap: " << this->name << " still has " << this->hit_points << " ammount of hit points left!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy_points <= 0)
	{
		std::cout << "Claptrap " << this->name << " has no energy points left" << std::endl;
		return ;
	}
	if (this->hit_points <= 0)
	{
		std::cout << "Claptrap " << this->name << " is dead!" << std::endl;
		return ;
	}
	this->energy_points -= 1;
	std::cout << "Claptrap " << this->name << " gets " << amount << " of hit points back" << std::endl;
	this->hit_points += amount;
	std::cout << "Claptrap: " << this->name << " still has " << this->hit_points << " ammount of hit points left!" << std::endl;
}