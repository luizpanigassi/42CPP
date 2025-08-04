#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

#include <iostream>
#include <string>

class Dog : public AAnimal
{
public:
	// Constructors and Destructor
	Dog();
	~Dog();
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);

	void makeSound() const;
	Brain* getBrain(void) const;

private:
	Brain* brain;
};

#endif
