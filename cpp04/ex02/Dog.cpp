#include "Dog.hpp"

Dog::Dog() : AAnimal()
{
	type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog constructor called!" << std::endl;
}

Dog::~Dog()
{
	std::cout << "We sent the dog to the \"farm\"!" << std::endl;
	delete this->brain;
}

Dog::Dog(const Dog& other) : AAnimal(other)
{
	std::cout << "Dog copy constructor called!" << std::endl;
	this->brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog assignment operator called!" << std::endl;
	if (this != &other)
	{
		delete (this->brain);
		this->brain = new Brain(*other.brain);
		this->type = other.type;
	}
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Woof woof! 🐶" << std::endl;
}

Brain* Dog::getBrain(void) const{
	return(this->brain);
}
