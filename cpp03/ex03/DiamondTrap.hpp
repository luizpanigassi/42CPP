#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "Claptrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string name;

	public:
		DiamondTrap(std::string name);
		~DiamondTrap();

		using ScavTrap::attack;

		void whoAmI();
};

#endif
