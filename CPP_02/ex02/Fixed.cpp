
#include "Fixed.hpp"

Fixed::Fixed() : rawValue(0) {}

Fixed::Fixed(const Fixed& other) {
	*this = other;
}

Fixed &Fixed::operator=(const Fixed& other) {
	if (this != &other) {
		rawValue = other.getRawBits();
	}
	return *this;
}

Fixed::Fixed(int integer) {
	rawValue = integer << fractionalBits;
}

Fixed::Fixed(float floating) {
	rawValue = roundf(floating * (1 << fractionalBits));
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const {
	return rawValue;
}

void Fixed::setRawBits(int const NewRawValue) {
	rawValue = NewRawValue;
}

float Fixed::toFloat() const {
	return static_cast<float>(rawValue) / (1 << fractionalBits);
}

int Fixed::toInt() const {
	return rawValue >> fractionalBits;
}

std::ostream& operator<<(std::ostream &out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}

bool Fixed::operator>(const Fixed &other) const {
	return this->rawValue > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const {
	return this->rawValue < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const {
	return this->rawValue >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const {
	return this->rawValue <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const {
	return this->rawValue == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const {
	return this->rawValue != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed &other) const {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++() {
	this->rawValue++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed &Fixed::operator--() {
	this->rawValue--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	operator--();
	return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return a < b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return a > b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return a > b ? a : b;
}