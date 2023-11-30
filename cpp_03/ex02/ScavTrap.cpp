#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap constructor is called and name is set!" << std::endl;
	this->name = name;
	this->hit_points = ClapTrap::hit_points;
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
	std::cout << "Scavtrap: " << this->name << " is charging towards " << target << ", dealing " << this->attack_damage << " ammount of damage" << std::endl;
	this->energy_points -= 1;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "Scavtrap " << this->name << " is tasked to guard the gate!" << std::endl;
}