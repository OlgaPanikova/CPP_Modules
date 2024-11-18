/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelichik <lelichik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:42:06 by lelichik          #+#    #+#             */
/*   Updated: 2024/11/18 19:36:50 by lelichik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : name(name), weapon(nullptr) {}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon& newWeapon)
{
		weapon = &newWeapon;
}

void HumanB::attack()
{
	if(weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " has no weapon to attack!" << std::endl;
}
