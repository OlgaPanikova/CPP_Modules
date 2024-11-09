/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelichik <lelichik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:47:32 by lelichik          #+#    #+#             */
/*   Updated: 2024/11/09 22:23:31 by lelichik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip> 
#include <cctype>

void PhoneBook::addContact()
{
	if(currentIndex == 8)
		currentIndex = 0;
	contacts[currentIndex].enterContact();
	currentIndex++;
	if(countContacts < 8)
		countContacts++;
}

void PhoneBook::searchContact(int index) const
{
	std::cout << "First name: " << contacts[index].getFirstName() << std::endl;
	std::cout << "Last name: " << contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
	std::cout << "Phone number: " << contacts[index].getPhoneNumber() << std::endl;;
	std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;;
}

void PhoneBook::displayContactsIndex() const
{
	std::string input;
	int index;
	
	while(1)
	{
		std::cout << "Enter the contact's index: ";
		std::getline(std::cin, input);
		if(!std::getline(std::cin, input))
		{
			if (std::cin.eof())
			{
				std::cout << "The end of the input has been detected (Ctrl+D). The existing program is closed" << std::endl;
				exit (1);
			}
		}
		index = atoi(input.c_str());
		if(index < 1 || index > currentIndex)
			std::cout << "Invalid index! Please enter the index in the range from 1 to " << currentIndex << std::endl;
		else
			break;
	}
		searchContact(index - 1);
}

int PhoneBook::displayContacts() const
{
	if (countContacts == 0)
	{
		std::cout << "PhoneBook is empty! You must first add contacts using the ADD command" << std::endl;
		return 1;
	}
	std::cout << "Contact List:\n";
	std::cout << std::right << std::setw(10) << "Index" << "|";
	std::cout << std::right << std::setw(10) << "First Name" << "|";
	std::cout << std::right << std::setw(10) << "Last Name" << "|";
	std::cout << std::right << std::setw(10) << "Nickname" << "|" << std::endl;
	for (int i = 0; i < countContacts; i++)
	{
		std::cout << std::right << std::setw(10) << (i + 1) << "|";

		if (contacts[i].getFirstName().length() > 10)
			std::cout << std::setw(10) << contacts[i].getFirstName().substr(0, 9) + "." << "|";
		else
			std::cout << std::setw(10) << contacts[i].getFirstName() << "|";
		if (contacts[i].getLastName().length() > 10)
			std::cout << std::setw(10) << contacts[i].getLastName().substr(0, 9) + "." << "|";
		else
			std::cout << std::setw(10) << contacts[i].getLastName() << "|";
		if (contacts[i].getNickname().length() > 10)
			std::cout << std::setw(10) << contacts[i].getNickname().substr(0, 9) + "." << "|";
		else
			std::cout << std::setw(10) << contacts[i].getNickname() << "|" << std::endl;
	}
	return 0;
}