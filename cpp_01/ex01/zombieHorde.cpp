#include "Zombie.hpp"

Zombie	*zombieHorde( int N, std::string name )
{
	Zombie *zombieHorde = new Zombie[N];

	std::cout << "" << std::endl;
	for (int i = 0; i < N; i++)
	{
		zombieHorde[i].setName(name);
	}
	return (zombieHorde);
}