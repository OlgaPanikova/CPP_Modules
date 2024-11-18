/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelichik <lelichik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:29:37 by lelichik          #+#    #+#             */
/*   Updated: 2024/11/18 18:04:55 by lelichik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int main(int argc, char **argv)
{
	if(argc != 4)
	{
		std::cerr << "Error: Usage: " << argv[0] << " with <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	Replace replace(argv[1], argv[2], argv[3]);
	if(replace.checkArguments())
		return 1;
	if(replace.readFile())
		return 1;
	replace.replaceOccurrences();
	if(replace.writeFile())
		return 1;
	return 0;
}