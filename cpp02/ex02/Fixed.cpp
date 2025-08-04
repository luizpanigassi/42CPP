#include "Fixed.hpp"

// CONSTRUCTORS
Fixed::Fixed() : fixed_point_value(0) {}

Fixed::Fixed(const int number)
{
	fixed_point_value = number << fractional_bits;
}

Fixed::Fixed(const float number)
{
	fixed_point_value = roundf(number * (1 << fractional_bits));
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		fixed_point_value = other.fixed_point_value;
	return *this;
}

// DESTRUCTOR
Fixed::~Fixed() {}

// FUNCTIONS
// Getters and setters for the fixed point value
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

// Conversion functions to convert fixed point value to float and int
float Fixed::toFloat(void) const
{
	return (float)fixed_point_value / (1 << fractional_bits);
}

int Fixed::toInt(void) const
{
	return fixed_point_value >> fractional_bits;
}

// OVERLOARDING
// Overloading the output operator to print Fixed objects
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

// Comparison operators
bool Fixed::operator<(const Fixed &rhs) const
{
	return this->fixed_point_value < rhs.fixed_point_value;
}

bool Fixed::operator>(const Fixed &rhs) const
{
	return this->fixed_point_value > rhs.fixed_point_value;
}

bool Fixed::operator==(const Fixed &rhs) const
{
	return this->fixed_point_value == rhs.fixed_point_value;
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	return this->fixed_point_value >= rhs.fixed_point_value;
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	return this->fixed_point_value <= rhs.fixed_point_value;
}

bool Fixed::operator!=(const Fixed &rhs) const
{
	return this->fixed_point_value != rhs.fixed_point_value;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed &rhs)const
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed &rhs)const
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed &rhs)const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed &rhs)const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

// Increment and decrement operators
Fixed &Fixed::operator++()
{
	++this->fixed_point_value;
	return *this;
}

Fixed &Fixed::operator--()
{
	--this->fixed_point_value;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	++this->fixed_point_value;
	return temp;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	--this->fixed_point_value;
	return temp;
}

// Min and max functions
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return a;
	return b;
}
