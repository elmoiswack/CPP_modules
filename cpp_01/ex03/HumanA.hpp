#ifndef HUMANA_HPP
# define	HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
private:
	std::string name;
	Weapon& weapons;
public:
	HumanA(std::string name, Weapon &club);
	~HumanA();
	void	attack(void);
};

#endif