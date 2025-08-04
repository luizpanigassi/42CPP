/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luinasci <luinasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:43:04 by luinasci          #+#    #+#             */
/*   Updated: 2025/06/16 17:38:57 by luinasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

PhoneBook::PhoneBook() : _contactCount(0), _nextIndex(0)
{

}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::addContact()
{
	_contacts[_nextIndex].setContact();
	if(_contactCount < 8)
		_contactCount++;
	_nextIndex = (_nextIndex + 1) % 8;
}

void PhoneBook::searchContact()
{
	if(_contactCount == 0)
	{
		std::cout << RED << "Wow, you don't have friends? Add a contact!" << RESET << std::endl;
		return;
	}
	std::cout << YELLOW << std::setw(10) << "Index"
			  << YELLOW << std::setw(10) << "First Name"
			  << YELLOW << std::setw(10) << "Last Name"
			  << YELLOW << std::setw(10) << "Nickname" << RESET << std::endl;
	for(int i = 0; i < _contactCount; i++)
		_contacts[i].displayShortContact(i);

	std::string input;
	std::cout << BLUE << "Which contact would you like to see? Give me the index:" << RESET;
	std::getline(std::cin, input);

	if(input.length() != 1 || !isdigit(input[0]))
	{
		std::cout << RED << "Whoops, invalid index." << RESET << std::endl;
		return;
	}
	int index = input [0] - '0';
	if(index >= _contactCount || index < 0)
	{
		std::cout << RED << "Got nothing there. Come on. Don't try to be funny." << RESET << std::endl;
		return;
	}

	std::cout << GREEN << "Here you go!" << RESET << std::endl;
	_contacts[index].displayFullContact();
}
