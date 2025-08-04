#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed
{
public:
	Fixed(); //default constructor
	Fixed(const int number); //int constructor
	Fixed(const float number); //float constructor
	Fixed(const Fixed &other); //copy constructor
	~Fixed(); // destructor
	Fixed &operator=(const Fixed &other); // copy assignment operator
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

private:
	int fixed_point_value;
	static const int fractional_bits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
