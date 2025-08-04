#include "Zombie.hpp"

Zombie::Zombie(const std::string& name) : name(name)
{
	std::cout << "Zombie " << name << " has risen from the grave!" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << name << " has been destroyed!" << std::endl;
}

void Zombie::announce() const
{
	std::cout << name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string Zombie::getName() const
{
	return name;
}
