#include "Cat.hpp"

Cat::Cat() : AAnimal()
{
	type = "Cat";
	std::cout << "Cat constructor called!" << std::endl;
	this->brain = new Brain();
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Poor baby, gone to cat heaven!" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other)
{
	std::cout << "Cat copy constructor called!" << std::endl;
	this->brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat assignment operator called!" << std::endl;
	if (this != &other)
	{
		delete this->brain;
		this->brain = new Brain(*other.brain);
		this->type = other.type;
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow! 😺" << std::endl;
}

Brain* Cat::getBrain(void) const{
	return(this->brain);
}
