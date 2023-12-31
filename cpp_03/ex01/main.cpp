#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap a("Albert");

	a.attack("Brad");
	a.takeDamage(5);
	a.beRepaired(10);

	std::cout << std::endl;
	ScavTrap b("Bert");

	b.attack("Klaas");
	b.takeDamage(8);
	b.beRepaired(9);
	b.guardGate();
}