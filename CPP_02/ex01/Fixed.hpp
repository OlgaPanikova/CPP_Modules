
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
	int					rawValue;
	static const int	fractionalBits = 8;

public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	Fixed(int integer);
	Fixed(float floating);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const NewRawValue);
	float toFloat() const;
	int toInt() const;
};

std::ostream& operator<<(std::ostream &out, const Fixed& fixed);

#endif