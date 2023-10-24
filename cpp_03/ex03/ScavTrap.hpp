#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
private:
	
public:
	ScavTrap();
	ScavTrap(std::string name);
	~ScavTrap();
	void	attack(const std::string& target);
	void	guardGate();
};

#endif