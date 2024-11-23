/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelichik <lelichik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:56:19 by lelichik          #+#    #+#             */
/*   Updated: 2024/11/23 21:05:49 by lelichik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

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