/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelichik <lelichik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:13:23 by lelichik          #+#    #+#             */
/*   Updated: 2024/11/23 21:01:13 by lelichik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : rawValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		rawValue = other.getRawBits();
	}
	return *this;
}

Fixed::Fixed(int integer) {
	std::cout << "Int constructor called" << std::endl;
	rawValue = integer << fractionalBits;
}

Fixed::Fixed(float floating) {
	std::cout << "Float constructor called" << std::endl;
	rawValue = roundf(floating * (1 << fractionalBits));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return rawValue;
}

void Fixed::setRawBits(int const NewRawValue) {
	std::cout << "setRawBits member function called" << std::endl;
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