#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

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

	std::cout << std::endl;
	
	FragTrap c("Charles");
	c.attack("Cleancy");
	c.takeDamage(7);
	c.beRepaired(3);
	c.highFivesGuys();

	std::cout << std::endl;	

	DiamondTrap d("Dirk");
	d.attack("Dave");
	d.takeDamage(20);
	d.beRepaired(25);
	d.whoAmI();

	std::cout << std::endl;	
}