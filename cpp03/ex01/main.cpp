#include "Claptrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap claptrap("Clappy");
	ScavTrap scavtrap("Scavvy");
	claptrap.attack("target1");
	claptrap.takeDamage(3);
	claptrap.beRepaired(2);
	scavtrap.attack("target2");
	scavtrap.takeDamage(5);
	scavtrap.beRepaired(3);
	scavtrap.guardGate();
	return 0;
}
