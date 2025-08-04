#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

#include <iostream>
#include <string>

class Cat : public Animal
{
public:
	// Constructors and Destructor
	Cat();
	~Cat();

	void makeSound() const;

private:
};

#endif
