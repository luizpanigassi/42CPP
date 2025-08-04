#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "Claptrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string name);
	~FragTrap();

	void highFivesGuys (void);
};

#endif
