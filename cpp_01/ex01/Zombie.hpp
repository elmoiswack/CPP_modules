#include <iostream>

#ifndef ZOMBIE_HPP
#define	ZOMBIE_HPP

class Zombie
{
private:
	std::string name;
public:
	Zombie(void);
	void	setName(std::string name);
	~Zombie();
	void	announce(void);
};

Zombie	*zombieHorde( int N, std::string name );

#endif