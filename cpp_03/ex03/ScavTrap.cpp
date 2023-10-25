#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap constructor is called and name is set!" << std::endl;
	this->name = name;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
}

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor without name is called!" << std::endl;
	this->name = "Empty";
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;	
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap deconstructor is called!" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->energy_points == 0)
	{
		std::cout << "ScavTrap " << this->name << " has no energy points left!";
		return ;
	}
	if (this->hit_points <= 0)
	{
		std::cout << "ScavTrap " << this->name << " is dead!" << std::endl;
		return ;
	}
	std::cout << "Scavtrap " << this->name << " attacks " << target << std::endl;
	this->energy_points -= 1;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "Scavtrap " << this->name << " is tasked to guard the gate!" << std::endl;
}