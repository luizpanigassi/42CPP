#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type(" Wrong Animal")
{
	std::cout << "Animal constructor called... kinda?" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Abomination euthanized humanely!" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Generic abomination noise!" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return type;
}
