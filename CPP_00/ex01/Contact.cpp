/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:01:44 by lelichik          #+#    #+#             */
/*   Updated: 2024/11/12 15:18:54 by opanikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"


	void Contact::setFirstName(const std::string& name) {
		firstName = name;
	}

	void Contact::setLastName(const std::string& name) {
		lastName = name;
	}

	void Contact::setNickname(const std::string& name) {
		nickname = name;
	}

	void Contact::setPhoneNumber(const std::string& number) {
		phoneNumber = number;
	}

	void Contact::setDarkestSecret(const std::string& secret) {
		darkestSecret = secret;
	}

	std::string Contact::getFirstName() const {
		return firstName;
	}

	std::string Contact::getLastName() const {
		return lastName;
	}

	std::string Contact::getNickname() const {
		return nickname;
	}

	std::string Contact::getPhoneNumber() const {
		return phoneNumber;
	}

	std::string Contact::getDarkestSecret() const {
		return darkestSecret;
	}

std::string getInput(const std::string& prompt)
{
	std::string result;
	bool checkSpace = false;
	while(true)
	{
		std::cout << prompt;
		if(!std::getline(std::cin, result))
		{
			if (std::cin.eof())
			{
				std::cout << "The end of the input has been detected (Ctrl+D). The existing program is closed" << std::endl;
				exit (0);
			}
		}
		for (size_t i = 0; i < result.length(); i++ )
		{
			if(result[i] == ' ')
				checkSpace = false;
			else
				checkSpace = true;
		}
		if(!result.empty() && checkSpace == true)
			break;
		else
			std::cout << "Input cannot be empty. Please try again.\n";
	}
	return result;
}

void	Contact::enterContact()
{
		setFirstName(getInput("Enter first name: "));
		setLastName(getInput("Enter last name: "));
		setNickname(getInput("Enter nickname: "));
		bool isValidPhoneNumber = false;
		while (!isValidPhoneNumber)
		{
			std::string input = getInput("Enter phone number: ");
			isValidPhoneNumber = true;
			for (size_t i = 0; i < input.length(); i++)
			{
				if (!std::isdigit(input[i]))
				{
					isValidPhoneNumber = false;
					std::cout << "Invalid phone number! Please enter only digits" << std::endl;
					break;
				}
			}
			if (isValidPhoneNumber)
				setPhoneNumber(input);
			else
				std::cout << "Try again: ";
		}
		setDarkestSecret(getInput("Enter darkest secret: "));
};
