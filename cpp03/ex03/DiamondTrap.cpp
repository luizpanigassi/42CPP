#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap (std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), name(name)
{
	this->name = name;
	ClapTrap::name = name + "_clap_name";

	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
	std::cout << "They call it Diamond, but... it's just a fancy ClapTrap with a shiny name!" << std::endl;
	std::cout << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "I guess " << name << " wasn't made of diamonds after all!" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am actually " << name << ", but my ClapTrap name is " << ClapTrap::name << "." << std::endl;
	std::cout << "Confusing, I know. But I am basically a Frankenstein of ClapTrap, ScavTrap, and FragTrap!" << std::endl;
	std::cout << std::endl;
}
