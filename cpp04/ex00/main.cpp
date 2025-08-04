#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << "=== Animal Sounds ===" << std::endl;

	const Animal* animal = new Animal();
	const Animal* doggo = new Dog();
	const Animal* catto = new Cat();

	std::cout << "\nTypes:" << std::endl;
	std::cout << "doggo is a " << doggo->getType() << std::endl;
	std::cout << "catto is a " << catto->getType() << std::endl;

	std::cout << "\nSounds:" << std::endl;
	catto->makeSound();
	doggo->makeSound();
	animal->makeSound();

	std::cout << "\n=== WrongAnimal ===" << std::endl;

	const WrongAnimal* wrong = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << "\nTypes:" << std::endl;
	std::cout << "wrongCat is a WrongAnimal*" << std::endl;

	std::cout << "\nSounds:" << std::endl;
	wrong->makeSound();
	wrongCat->makeSound();

	std::cout << "\n=== Destruction Time ===" << std::endl;

	delete animal;
	std::cout << std::endl;
	delete doggo;
	std::cout << std::endl;
	delete catto;
	std::cout << std::endl;
	delete wrong;
	std::cout << std::endl;
	delete wrongCat;
	std::cout << std::endl;

	return 0;
}
