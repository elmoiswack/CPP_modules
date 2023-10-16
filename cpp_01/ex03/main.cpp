#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int	main(void)
{
	std::cout << "Human A:" << std::endl;
	Weapon mace = Weapon("crude spiked mace");
	HumanA bob("Bob", mace);
	bob.attack();
	mace.setType("some other type of mace");
	bob.attack();

	std::cout << "" << std::endl;

	std::cout << "Human B:" << std::endl;
	Weapon sword = Weapon("shiny sharp sword");
	HumanB jim("Jim");
	jim.setWeapon(sword);
	jim.attack();
	sword.setType("some other type of sword");
	jim.attack();

	std::cout << "" << std::endl;
	return 0;
}