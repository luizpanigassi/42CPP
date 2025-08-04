#include "Claptrap.hpp"

ClapTrap::ClapTrap(std::string name) : hitPoints(10), energyPoints(10), attackDamage(0), name(name)
{
	std::cout << std::endl;
	std::cout << "ClapTrap " << name << " created!" << std::endl;
	std::cout << "ClapTrap: 'I am " << name << ", a CL4P-TP steward bot, but my friends call me Claptrap! "<< std::endl;
	std::cout << "Or they would, if any of them were still alive, or have existed in the first place!" << std::endl;
	std::cout << WHITE << "      ,\n";
	std::cout << WHITE <<"      |           " << name << "\n";
	std::cout << GRAY <<"   ]  |.-._\n";
	std::cout << YELLOW << "    \\|\"" << BLUE << "(0)" << YELLOW << "\"| _]\n";
	std::cout << YELLOW << "    `|=\\#/=|\\/\n";
	std::cout << GRAY << "     :  _  :\n";
	std::cout << WHITE << "      \\/_\\/\n";
	std::cout << WHITE << "       |=|\n";
	std::cout << WHITE << "       `-'\n";
	std::cout << RESET;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " destroyed!" << std::endl;
	std::cout << "Finally, he was annoying as hell!" << std::endl;
	std::cout << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (energyPoints <= 0)
	{
		std::cout << name << ": I'm too tired, boss, SUPERDUPER TIREEEEEEED!" << std::endl;
	}
	else
	{
		std::cout << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
		std::cout << name << ": SUPERDUPER ATTACK TIME! PZOW!" << std::endl;
	}
	energyPoints--;
	std::cout << "Energy points left: " << energyPoints << std::endl;
	std::cout << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	hitPoints -= amount;
	if (hitPoints <= 0)
	{
		std::cout << name << ": I'm dead, boss, SUPERDUPER DEEEEEAD!" << std::endl;
	}
	else
	{
		std::cout << name << " takes " << amount << " points of damage!" << std::endl;
		std::cout << name << ": That hurts! SUPERDUPER HUUUUURTS!" << std::endl;
	}
	std::cout << "Hit points left: " << hitPoints << std::endl;
	std::cout << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints <= 0)
	{
		std::cout << name << ": I'm too tired to self repair! SUPERDUPER TIREEEEEED!" << std::endl;
	}
	else
	{
		hitPoints += amount;
		energyPoints--;
		std::cout << name << " repairs itself for " << amount << " hit points!" << std::endl;
		std::cout << name << ": SUPERDUPER HEALTHYYYYYYY! YAY!" << std::endl;
		std::cout << "Hit points after repair: " << hitPoints << std::endl;
	}
	std::cout << "Energy points left: " << energyPoints << std::endl;
	std::cout << std::endl;
}
