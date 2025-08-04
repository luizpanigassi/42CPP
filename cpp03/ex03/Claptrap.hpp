#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define WHITE "\033[1;37m"
#define GRAY "\033[0;90m"
#define RESET "\033[0m"

class ClapTrap
{
public:
	// Constructors and Destructor
	ClapTrap(std::string name);
	~ClapTrap();
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

protected:
	int hitPoints;
	int energyPoints;
	int attackDamage;
	std::string name;
};

#endif
