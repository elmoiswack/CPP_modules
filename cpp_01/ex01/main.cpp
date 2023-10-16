#include "Zombie.hpp"

int	main(void)
{
	Zombie *horde;
	int	numb;

	numb = 10;
	horde = zombieHorde(numb, "Cartman");
	std::cout << "" << std::endl;
	for (int i = 0; i < numb; i++)
	{
		horde[i].announce();
	}
	std::cout << "" << std::endl;
	delete[] horde;
}