/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luinasci <luinasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 19:15:10 by luinasci          #+#    #+#             */
/*   Updated: 2025/06/16 16:23:19 by luinasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string truncateField(const std::string &str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	else
		return std::string(10 -str.length(), ' ') + str;
}

Contact::Contact()
{
}

Contact::~Contact()
{
}

std::string getNonEmptyLine(const std::string &prompt)
{
	std::string input;
	while(true)
	{
		std::cout << BLUE << prompt << RESET;
		if(!std::getline(std::cin, input))
		{
			if(std::cin.eof())
			{
				std::cout << RED << "\nWow, really? Quitting on me? Ok. Be gone, then." << RESET << std::endl;
				std::exit(1);
			}
			std::cin.clear();
			continue;
		}
		if (!input.empty())
			return input;
		std::cout << RED << "Dude. Seriously? You can't just leave it empty. Try again." << RESET << std::endl;
	}
}

void Contact::setContact()
{
	_firstName = getNonEmptyLine("Enter the first name, please: ");
	_lastName = getNonEmptyLine("Now the last name, please: ");
	_nickname = getNonEmptyLine("And the nickname, please: ");
	_phoneNumber = getNonEmptyLine("Great! Now, your phone number: ");
	_darkestSecret = getNonEmptyLine("Finally, your darkest secret: ");
	std::cout << GREEN << "All good, your contact has been saved!" << RESET << std::endl;
}

void Contact::displayShortContact(int index) const
{
	std::cout << YELLOW << std::setw(10) << index << "|"
			  << std::setw(10) << truncateField(_firstName) << "|"
			  << std::setw(10) << truncateField(_lastName) << "|"
			  << std::setw(10) << truncateField(_nickname) << "|"
			  << RESET << std::endl;
}

void Contact::displayFullContact() const
{
	std::cout << BLUE << "First Name: " << RESET << _firstName << std::endl;
	std::cout << BLUE << "Last Name: " << RESET <<_lastName << std::endl;
	std::cout << BLUE << "Nickname: " << RESET <<_nickname << std::endl;
	std::cout << BLUE << "Phone Number: " << RESET <<_phoneNumber << std::endl;
	std::cout << BLUE << "Darkest Secret: " << RESET <<_darkestSecret << std::endl;
}
