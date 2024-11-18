/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelichik <lelichik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:39:40 by lelichik          #+#    #+#             */
/*   Updated: 2024/11/18 19:37:06 by lelichik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB {
private:
	std::string name;
	Weapon* weapon;
public:
	HumanB(const std::string& name);
	~HumanB();
	void setWeapon(Weapon& newWeapon);
	void attack();
};

#endif