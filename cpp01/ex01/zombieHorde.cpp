#include "Zombie.hpp"

Zombie* zombieHorde(int N, const std::string& name)
{
	if (N <= 0)
	{
		std::cout << "I need corpses. I NEED MORE THAN 0!" << std::endl;
		return NULL;
	}

	Zombie* horde = new Zombie[N];
	int i = 0;
	while (i < N)
	{
		horde[i].setName(name);
		i++;
	}
	return horde;
}
