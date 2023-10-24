#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
{
	std::cout << "DaimondTrap constructor is called and name is set!" << std::endl;
	this->name = name;
	ClapTrap::name = name.append("_clap_name");
	this->hit_points = FragTrap::hit_points;
	this->energy_points = ScavTrap::energy_points;
	this->attack_damage = FragTrap::attack_damage;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DaimondTrap deconstructor is called!" << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "Daimond name = " << this->name << " and ClapTrap name = " << ClapTrap::name << std::endl;
}