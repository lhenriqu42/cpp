/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 08:40:03 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/04/15 10:52:54 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"
#include "colors.h"

int	main(void)
{
	std::string line;
	PhoneBook ph;

	while (line != "EXIT")
	{
		std::cout << C_CYA "Enter a command > " C_RST;
		std::getline(std::cin, line);
		std::cout << C_UP C_CUT;
		if (line == "ADD")
			ph.add();
		else if (line == "SEARCH")
			ph.search();
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (0);
		}
	}
	return (0);
}