#ifndef DAIMONDTRAP_HPP
# define DAIMONDTRAP_HPP

#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public virtual ScavTrap, public virtual FragTrap
{
private:
	std::string name;
public:
	DiamondTrap(std::string name);
	~DiamondTrap();
	void attack(const std::string& target);
	void whoAmI();
};


#endif