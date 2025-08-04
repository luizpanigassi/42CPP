#include "Dog.hpp"

Dog::Dog() : Animal()
{
	type = "Dog";
	std::cout << "Dog constructor called!" << std::endl;
}

Dog::~Dog()
{
	std::cout << "We sent the dog to the \"farm\"!" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof woof! 🐶" << std::endl;
}
