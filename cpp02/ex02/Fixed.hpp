#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed
{
public:
	// Constructors
	Fixed();
	Fixed(const int number);
	Fixed(const float number);
	Fixed(const Fixed &other);

	// Destructor
	~Fixed();

	// Copy assignment operator
	Fixed &operator=(const Fixed &other);

	// Getters and setters for the fixed point value
	int getRawBits(void) const;
	void setRawBits(int const raw);

	// Conversion functions
	float toFloat(void) const;
	int toInt(void) const;

	// OPERATORS
	// Comparison
	bool operator>(const Fixed &rhs) const;
	bool operator<(const Fixed &rhs) const;
	bool operator>=(const Fixed &rhs) const;
	bool operator<=(const Fixed &rhs) const;
	bool operator==(const Fixed &rhs) const;
	bool operator!=(const Fixed &rhs) const;

	// Arithmetic
	Fixed operator+(const Fixed &rhs) const;
	Fixed operator-(const Fixed &rhs) const;
	Fixed operator*(const Fixed &rhs) const;
	Fixed operator/(const Fixed &rhs) const;

	// Increment and decrement
	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);

	// Min and max
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);

private:
	int fixed_point_value;
	static const int fractional_bits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
