#include <iostream>

#ifndef WEAPON_HPP
# define	WEAPON_HPP

class Weapon
{
private:
	std::string type;
public:
	Weapon(std::string newtype);
	~Weapon();
	const std::string& getType(void);
	void	setType(std::string newtype);
};

#endif