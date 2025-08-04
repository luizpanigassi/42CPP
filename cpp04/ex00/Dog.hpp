#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

#include <iostream>
#include <string>

class Dog : public Animal
{
public:
	// Constructors and Destructor
	Dog();
	~Dog();

	void makeSound() const;

private:
};

#endif
