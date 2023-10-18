#include "Zombie.hpp"

int	main(void)
{
	Zombie *jack;
	Zombie *mark;
	Zombie *kevin;

	std::cout << "allocating newZombies!" << std::endl;
	jack = newZombie("jack");
	mark = newZombie("mark");
	kevin = newZombie("kevin");

	jack->announce();
	mark->announce();
	kevin->announce();

	std::cout << std::endl;
	delete jack;
	delete mark;
	delete kevin;

	std::cout << "\nRandom chumps:"  << std::endl;
	randomChump("Cartman");
	randomChump("Kyle");
	randomChump("Kenny");
	randomChump("Stan");


	return (0);
}