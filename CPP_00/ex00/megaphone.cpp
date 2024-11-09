/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelichik <lelichik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:20:42 by lelichik          #+#    #+#             */
/*   Updated: 2024/11/06 13:34:45 by lelichik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	int i = 1;
	
	if(argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while(i < argc)
	{
		int j = 0;
		while(argv[i][j])
		{
			std::cout << char(toupper(argv[i][j]));
			j++;
		}
		i++;
		if(i < argc)
		{
			std::cout << " ";
		}
	}
	std::cout << std::endl;
}