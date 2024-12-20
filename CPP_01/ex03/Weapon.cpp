/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelichik <lelichik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:32:40 by lelichik          #+#    #+#             */
/*   Updated: 2024/11/18 19:37:26 by lelichik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& initialType) : type(initialType) {}

Weapon::~Weapon() {}

const std::string& Weapon::getType() const
{
	return type;
}

void Weapon::setType(const std::string& newType)
{
	type = newType;
}