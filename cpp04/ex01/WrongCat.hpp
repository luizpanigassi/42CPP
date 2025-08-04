#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

#include <iostream>
#include <string>

class WrongCat : public WrongAnimal
{
public:
	// Constructors and Destructor
	WrongCat();
	~WrongCat();

	void makeSound() const;

private:

};

#endif
