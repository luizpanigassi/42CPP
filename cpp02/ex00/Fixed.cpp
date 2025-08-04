#include "Fixed.hpp"

Fixed::Fixed() : fixed_point_value(0)
{
	std::cout << "Construtor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called!" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		fixed_point_value = other.fixed_point_value;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called, bye!" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits called" << std::endl;
	return fixed_point_value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "calling setRawBits with value: " << raw << std::endl;
	fixed_point_value = raw;
}
