#include "Zombie.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << "===== Time to raise the dead! =====" << std::endl;
	std::cout << std::endl;
	Zombie* horde = zombieHorde(5, "John Rando");

	int i = 0;
	while (i < 5)
	{
		horde[i].announce();
		i++;
	}

	std::cout << std::endl;

	std::cout << "===== Time to put them back in their graves! =====" << std::endl;
	std::cout << std::endl;
	delete[] horde;
	std::cout << "The dead sleep again." << std::endl;
	std::cout << std::endl;
	return 0;
}
