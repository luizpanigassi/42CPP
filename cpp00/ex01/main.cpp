/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luinasci <luinasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 19:15:58 by luinasci          #+#    #+#             */
/*   Updated: 2025/06/16 16:20:26 by luinasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main ()
{
	PhoneBook phonebook;
	std::cout << CYAN << "Hi! I'm a phonebook!" << RESET << std::endl;
	while (true)
	{
		std::string command;
		std::cout << "So, what do you wanna do today? (add/search/exit): ";
		if (!std::getline(std::cin, command))
		{
			std::cout << RED << "\nWait, you can't just quit! GET BACK HERE!" << RESET << std::endl;
			break;
		}
		if(command == "add")
			phonebook.addContact();
		else if (command == "search")
			phonebook.searchContact();
		else if (command == "exit")
		{
			std::cout << RED << "Ok, I'm deleting EVERYTHING now, see you later!" << RESET << std::endl;
			break ;
		}
		else
			std::cout << RED << "I said add, search or exit, idiot. Try again." << RESET << std::endl;
	}
	return 0;
}
