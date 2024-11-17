/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelichik <lelichik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:13:56 by lelichik          #+#    #+#             */
/*   Updated: 2024/11/17 21:19:10 by lelichik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

int main()
{
	Weapon one("Gun");

	std::cout << "Initial Weapon Type: " << one.getType() << std::endl;

	one.setType("Sword");
	std::cout << "Updated Weapon Type: " << one.getType() << std::endl;

	return 0;
}