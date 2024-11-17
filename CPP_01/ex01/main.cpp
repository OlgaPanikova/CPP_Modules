/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelichik <lelichik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:04:57 by opanikov          #+#    #+#             */
/*   Updated: 2024/11/17 14:42:18 by lelichik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int	main()
{
	int i = 5;
	Zombie *zombHorde = zombieHorde(i, "Paul");
	for(int j = 0; j < i; j++)
	{
		zombHorde[j].announce();
	}
	delete[] zombHorde;
	//system("leaks MoarBrainz");
	return 0;
}