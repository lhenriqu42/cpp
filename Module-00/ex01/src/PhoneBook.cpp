/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:06:56 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/04/15 13:14:59 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"
#include "colors.h"
#include <string>

PhoneBook::PhoneBook()
{
	this->_index = 0;
}

PhoneBook::~PhoneBook()
{
}

std::string PhoneBook::trim(const std::string &str)
{
	std::string trimmed = str;
	trimmed.erase(0, trimmed.find_first_not_of(" \t\n\r\f\v"));
	trimmed.erase(trimmed.find_last_not_of(" \t\n\r\f\v") + 1);
	return (trimmed);
}

void PhoneBook::add(void)
{
	std::string str;
	
	std::cout << C_PUR " -- ADDING SECTION -- " C_RST << std::endl;
	str = "";
	if (this->_index > 7)
		std::cout << C_RED "Warning: overwriting info about " C_CYA << this->_list[this->_index % 8].get_fname() << C_RST << std::endl;
	while (!std::cin.eof() && str.empty())
	{
		std::cout << C_BLU "First name: " C_RST;
		std::getline(std::cin, str);
		str = trim(str);
		if (str.empty())
			std::cout << C_UP C_CUT;
		else
			this->_list[this->_index % 8].set_fname(str);
	}
	str = "";
	while (!std::cin.eof() && str.empty())
	{
		std::cout << C_BLU "Last name: " C_RST;
		std::getline(std::cin, str);
		str = trim(str);
		if (str.empty())
			std::cout << C_UP C_CUT;
		else
			this->_list[this->_index % 8].set_lname(str);
	}
	str = "";
	while (!std::cin.eof() && str.empty())
	{
		std::cout << C_BLU "Nickname: " C_RST;
		std::getline(std::cin, str);
		str = trim(str);
		if (str.empty())
			std::cout << C_UP C_CUT;
		else
			this->_list[this->_index % 8].set_nick(str);
	}
	str = "";
	while (!std::cin.eof() && str.empty())
	{
		std::cout << C_BLU "Phone number: " C_RST;
		std::getline(std::cin, str);
		str = trim(str);
		if (str.empty())
			std::cout << C_UP C_CUT;
		else
			this->_list[this->_index % 8].set_phone_num(str);
	}
	str = "";
	while (!std::cin.eof() && str.empty())
	{
		std::cout << C_BLU "Darkest secret: " C_RST;
		std::getline(std::cin, str);
		str = trim(str);
		if (str.empty())
			std::cout << C_UP C_CUT;
		else
			this->_list[this->_index % 8].set_secret(str);
	}
}

void PhoneBook::search(void)
{
}
