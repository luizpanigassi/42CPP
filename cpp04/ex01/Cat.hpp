#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

#include <iostream>
#include <string>

class Cat : public Animal
{
public:
	// Constructors and Destructor
	Cat();
	~Cat();
	Cat(const Cat& other);
	Cat& operator=(const Cat& other);

	void makeSound() const;
	Brain* getBrain(void) const;

private:
	Brain* brain;
};

#endif
