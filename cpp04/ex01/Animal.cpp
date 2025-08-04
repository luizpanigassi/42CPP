#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal constructor called!" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal euthanized humanely!" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type)
{
	std::cout << "Animal copy constructor called!" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Animal assignment operator called!" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "Generic animal sound!" << std::endl;
}

std::string Animal::getType() const
{
	return type;
}
