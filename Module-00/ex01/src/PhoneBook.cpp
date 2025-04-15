/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:06:56 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/04/15 18:12:33 by lhenriqu         ###   ########.fr       */
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

void PhoneBook::get_info(Contact& current, const std::string& str, void (Contact::*setter)(const std::string&))
{
	std::string line;

	line = "";
	while (!std::cin.eof() && line.empty())
	{
		std::cout << C_BLU << str << C_RST;
		std::getline(std::cin, line);
		line = trim(line);
		if (line.empty())
			std::cout << C_UP C_CUT;
		else
			(current.*setter)(line);
	}
}

void PhoneBook::add(void)
{
	Contact& current = this->_list[this->_index % 8];

	std::cout << C_PUR " -- ADDING SECTION -- " C_RST << std::endl;
	if (this->_index > 7)
		std::cout << C_RED "Warning: overwriting info about " C_CYA << current.get_fname() << C_RST << std::endl;
	get_info(current, "First name: ", &Contact::set_fname);
	get_info(current, "Last name: ", &Contact::set_lname);
	get_info(current, "Nickname: ", &Contact::set_nick);
	get_info(current, "Phone number: ", &Contact::set_phone_num);
	get_info(current, "Darkest secret: ", &Contact::set_secret);
	for(int i = 0; i < 6; i++)
		std::cout << C_UP C_CUT;
	std::cout << C_GRN "Success to register: " C_CYA << current.get_fname() << C_RST "." << std::endl;
}

void PhoneBook::search(void)
{
}
