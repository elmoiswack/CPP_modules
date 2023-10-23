#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap a("Albert");

	a.attack("Brad");
	a.takeDamage(5);
	a.beRepaired(10);
}