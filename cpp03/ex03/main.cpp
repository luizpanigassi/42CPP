#include "Claptrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	ClapTrap claptrap("Clappy");
	ScavTrap scavtrap("Scavvy");
	FragTrap fragtrap("Fraggy");
	DiamondTrap diamondtrap("Diamondy");
	claptrap.attack("target1");
	claptrap.takeDamage(3);
	claptrap.beRepaired(2);
	scavtrap.attack("target2");
	scavtrap.takeDamage(5);
	scavtrap.beRepaired(3);
	scavtrap.guardGate();
	fragtrap.attack("target3");
	fragtrap.takeDamage(5);
	fragtrap.beRepaired(3);
	fragtrap.highFivesGuys();
	diamondtrap.attack("target4");
	diamondtrap.takeDamage(5);
	diamondtrap.beRepaired(3);
	diamondtrap.whoAmI();

	return 0;
}
