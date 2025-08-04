#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal
{
public:
	// Constructors and Destructor
	AAnimal();
	AAnimal(const AAnimal& other);
	AAnimal& operator=(const AAnimal& other);
	virtual ~AAnimal();

	virtual void makeSound() const = 0;
	std::string getType() const;

protected:
	std::string type;
};

#endif
