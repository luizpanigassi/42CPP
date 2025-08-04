#include "Zombie.hpp"

Zombie* newZombie(const std::string& name);
void randomChump(const std::string& name);

int main()
{
	std::cout << std::endl;

	std::cout << "===== Creating a zombie in the heap... =====" << std::endl;
	std::cout << std::endl;
	Zombie* heapZombie = newZombie("Jeffrey Heapman");
	heapZombie->announce();
	std::cout << std::endl;
	std::cout << "===== Deleting " << heapZombie->getName() << " from the heap... =====" << std::endl;
	std::cout << " == " << heapZombie->getName() << " deleted! == " << std::endl;
	delete heapZombie;

	std::cout << std::endl;

	std::cout << "===== Creating a zombie on the stack... =====" << std::endl;
	std::cout << std::endl;
	randomChump("Stacky McStackface");
	std::cout << std::endl;
	std::cout << "===== HAHA, we don't need to delete him, he just exploded =====" << std::endl;
	std::cout << " == Stack zombie deleted! ==" << std::endl;

	std::cout << std::endl;

	return 0;
}
