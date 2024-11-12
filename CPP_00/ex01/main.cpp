/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:12:02 by lelichik          #+#    #+#             */
/*   Updated: 2024/11/12 15:19:14 by opanikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
	PhoneBook	phoneBook;
	std::string command;
	
	while(1)
	{
		std::cout << "Enter one of the commands: ADD, SEARCH, EXIT" << std::endl;
		std::getline(std::cin, command);
		if(command == "ADD")
			phoneBook.addContact();
		if(command == "SEARCH")
		{
			if(phoneBook.displayContacts() == 1)
				continue;
			phoneBook.displayContactsIndex();
		}
		if(command == "EXIT")
			break;
		if (std::cin.eof())
			return 0;
	}
	return 0;
}
