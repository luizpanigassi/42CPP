#include "Claptrap.hpp"

int main()
{
	ClapTrap claptrap("Clappy");
	claptrap.attack("target1");
	claptrap.takeDamage(3);
	claptrap.beRepaired(2);
	return 0;
}
