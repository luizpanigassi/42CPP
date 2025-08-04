#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "Don't forget, he is a mere ScavTrap!" << std::endl;
	std::cout << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "We're about to crush a ScavTrap!" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (energyPoints <= 0)
	{
		std::cout << name << ": No can dosville, babydoll! ZERO ENERGY!" << std::endl;
	}
	else
	{
		std::cout << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
		std::cout << name << ": SUPERDUPER SCAV ATTACK, DUMMIES!" << std::endl;
	}
	energyPoints--;
	std::cout << "Energy points left: " << energyPoints << std::endl;
	std::cout << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << name << ": GUARDING THE GATE! YOU SHALL NOT PASS!" << std::endl;
	std::cout << name << " is now in Gate Keeper mode! Scary... or not." << std::endl;
	std::cout << std::endl;
}
