#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "This one is a FragTrap. He's... special. And explosive!" << std::endl;
	std::cout << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "Your FragTrap is ticking... OH NO!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << name << ": GUYS! LET'S HIGH FIVE! I LOVE HIGH FIVES!" << std::endl;
	std::cout << "*wild cricket noises*" << std::endl;
	std::cout << std::endl;
}
