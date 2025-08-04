/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luinasci <luinasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:01:36 by luinasci          #+#    #+#             */
/*   Updated: 2025/06/12 17:17:54 by luinasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	else
	{
		for(int i = 1; i < argc; ++i)
		{
			for(int j = 0; argv[i][j] != '\0'; ++j)
			{
				std::cout << static_cast<char>(std::toupper(argv[i][j]));
			}
		}
	}
	return 0;
}
