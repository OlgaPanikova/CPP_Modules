/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelichik <lelichik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:04:57 by opanikov          #+#    #+#             */
/*   Updated: 2024/11/17 14:42:56 by lelichik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int	main()
{
	Zombie	*onHeap = newZombie("Fred"); // нужно ли добавлять обьявление?
	delete onHeap;
	randomChump("Nick");
	//system("leaks BraiiiiiiinnnzzzZ");
	return 0;
}