#include "Fixed.hpp"

Fixed::Fixed() : fixed_point_value(0)
{
	std::cout << "Default construtor called" << std::endl;
}

Fixed::Fixed(const int number)
{
	std::cout << "Int construtor called" << std::endl;
	fixed_point_value = number << fractional_bits;
}

Fixed::Fixed(const float number)
{
	std::cout << "Float construtor called" << std::endl;
	fixed_point_value = roundf(number * (1 << fractional_bits));
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

float Fixed::toFloat(void) const
{
	return (float)fixed_point_value / (1 << fractional_bits);
}

int Fixed::toInt(void) const
{
	return fixed_point_value >> fractional_bits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
