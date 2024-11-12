/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:24:03 by lelichik          #+#    #+#             */
/*   Updated: 2024/11/12 15:18:26 by opanikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include <iomanip> 
#include <cctype>
#include "Contact.hpp"

class PhoneBook {
private:
	Contact contacts[8];
	int currentIndex;
	int countContacts;
	
public:
	PhoneBook() : currentIndex(0), countContacts(0) {}
	void addContact();
	int displayContacts() const;
	void displayContactsIndex() const;
	void searchContact(int index) const;
};

#endif