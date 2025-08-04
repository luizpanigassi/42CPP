#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal constructor called!" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal euthanized humanely!" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Generic animal sound!" << std::endl;
}

std::string Animal::getType() const
{
	return type;
}
