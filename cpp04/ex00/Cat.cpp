#include "Cat.hpp"

Cat::Cat() : Animal()
{
	type = "Cat";
	std::cout << "Cat constructor called!" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Poor baby, gone to cat heaven!" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow! 😺" << std::endl;
}
