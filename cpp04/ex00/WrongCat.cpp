#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	type = "WrongCat";
	std::cout << "WrongCat constructor called!" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "AAAH KILL IT WITH FIRE!" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "SHAZOOM!" << std::endl;
}
