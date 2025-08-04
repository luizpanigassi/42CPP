#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
	std::cout << "AAnimal constructor called!" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal euthanized humanely!" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : type(other.type)
{
	std::cout << "AAnimal copy constructor called!" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
	std::cout << "AAnimal assignment operator called!" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

void AAnimal::makeSound() const
{
	std::cout << "Generic AAnimal sound!" << std::endl;
}

std::string AAnimal::getType() const
{
	return type;
}
