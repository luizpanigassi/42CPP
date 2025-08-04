#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
public:
	// Constructors and Destructor
	WrongAnimal();
	~WrongAnimal();

	void makeSound() const;
	std::string getType() const;

protected:
	std::string type;
};

#endif
