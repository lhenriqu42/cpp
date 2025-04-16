/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:06:56 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/04/16 15:08:38 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"
#include "colors.h"
#include <string>

PhoneBook::PhoneBook() : _index(0)
{
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
static bool isAsciiOnly(const std::string& str)
{
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (static_cast<unsigned char>(str[i]) > 127)
			return false;
	}
	return true;
}

void PhoneBook::getInfo(Contact& current, const std::string& str, void (Contact::*setter)(const std::string&))
{
	std::string line;

	line = "";
	while (!std::cin.eof() && (line.empty() || !isAsciiOnly(line)))
	{
		std::cout << C_BLU << str << C_RST;
		std::getline(std::cin, line);
		line = trim(line);
		if (std::cin.eof())
			return ;
		if (line.empty() || !isAsciiOnly(line))
			std::cout << C_UP C_CUT;
		else
			(current.*setter)(line);
	}
}

void PhoneBook::add(void)
{
	Contact& current = this->_list[this->_index % 8];

	std::cout << C_PUR "╔══════════════════════════════╗" C_RST << std::endl;
	std::cout << C_PUR "║    " C_WHT " -- ADDING SECTION -- " C_RST "    ║" C_RST << std::endl;
	std::cout << C_PUR "╚══════════════════════════════╝" C_RST << std::endl;
	if (this->_index > 7)
		std::cout << C_RED "Warning: overwriting info about " C_CYA << current.get_fname() << C_RST << std::endl;
	getInfo(current, "First name: ", &Contact::set_fname);
	getInfo(current, "Last name: ", &Contact::set_lname);
	getInfo(current, "Nickname: ", &Contact::set_nick);
	getInfo(current, "Phone number: ", &Contact::set_phone_num);
	getInfo(current, "Darkest secret: ", &Contact::set_secret);
	int lines_to_cut = std::cin.eof() ? 0 : this->_index > 7 ? 9 : 8;
	for(int i = 0; i < lines_to_cut; i++)
		std::cout << C_UP C_CUT;
	if (!std::cin.eof())
	{
		std::cout << C_GRN "Success to register: " C_CYA << current.get_fname() << C_RST "." << std::endl;
		this->_index++;
	}
}

static std::string formatString(const std::string& str, size_t max_size)
{
	if (str.size() > max_size)
		return str.substr(0, max_size - 1) + ".";
	else
		return std::string(max_size - str.size(), ' ') + str;
}
static bool validateLine(const std::string& line, size_t index)
{
	if (line.size() != 1)
		return false;

	size_t c = line[0];
	if (!std::isdigit(c))
		return false;
	c = (c - '0');
	if (c < 1 || c > index || c > 8)
		return false;
	return true;
}

void PhoneBook::search(void)
{
	if (this->_index == 0)
	{
		std::cout << C_RED "No contacts to search. Please ADD a new contact." C_RST << std::endl;
		return ;
	}

	std::cout << "╔════════════════════════════════════════════════════════════╗\n";
    std::cout << "║                          CONTACTS                          ║\n";
    std::cout << "╠════════════════╦═════════════╦════════════╦════════════════╣\n";
    std::cout << "║    FIRST NAME  ║  LAST NAME  ║  NICKNAME  ║  PHONE NUMBER  ║\n";
	std::cout << "╠════════════════╬═════════════╬════════════╬════════════════╣\n";
	for(int i = 0; i < 8; i++)
	{
		Contact& current = this->_list[i];
		if (current.get_fname().size())
		{
			std::cout << "║ " << i + 1 << ". " 
				<< formatString(current.get_fname(), 11) << " ║ " 
				<< formatString(current.get_lname(), 11) << " ║ " 
				<< formatString(current.get_nick(), 10) << " ║ " 
				<< formatString(current.get_phone_num(), 14) << " ║\n";
		}
	}
	std::cout << "╚════════════════╩═════════════╩════════════╩════════════════╝\n";
	std::string line = "";
	while (true)
	{
		std::cout << C_BLU "Chose an index to view details: " C_RST;
		std::getline(std::cin, line);
		line = trim(line);
		if (std::cin.eof())
			return ;
		if (!validateLine(line, this->_index))
			std::cout << C_UP C_CUT;
		else
		{
			getContactDetails(line[0] - '0');
			break ;
		}
	}
}

void PhoneBook::printMenu(void)
{
	std::cout << C_YEL;
	std::cout << "╔══════════════════════════════╗" << std::endl;
    std::cout << "║          " C_WHT "PHONEBOOK" C_YEL "           ║" << std::endl;
    std::cout << "╠══════════════════════════════╣" << std::endl;
    std::cout << "║ ⮞ ADD - " C_WHT "Adicionar contato" C_YEL "    ║" << std::endl;
    std::cout << "║ ⮞ SEARCH - " C_WHT "Buscar contatos" C_YEL "   ║" << std::endl;
    std::cout << "║ ⮞ EXIT - " C_WHT "Sair do Programa" C_YEL "    ║" << std::endl;
    std::cout << "╚══════════════════════════════╝" << std::endl;
	std::cout << C_RST;
}
void PhoneBook::getContactDetails(int index)
{
	size_t lines_to_cut = this->_index + 7;
	for(size_t i = 0; i < lines_to_cut; i++)
		std::cout << C_UP C_CUT;
	
	std::cout << "╔══════════════════════════════════╗\n";
	std::cout << "║ Contact: " << formatString(_list[index].get_fname(), 23) << " ║\n";
	std::cout << "╚══════════════════════════════════╝\n";
	std::cout << C_BLU << "Fisrt name: " << C_RST << _list[index].get_fname() << std::endl;
	std::cout << C_BLU << "Last name: " << C_RST << _list[index].get_lname() << std::endl;
	std::cout << C_BLU << "Nickname: " << C_RST << _list[index].get_nick() << std::endl;
	std::cout << C_BLU << "Phone number: " << C_RST << _list[index].get_phone_num() << std::endl;
	std::cout << C_BLU << "Darkest secret: " << C_RST << _list[index].get_secret() << std::endl << std::endl;
	std::cin.ignore(10000, '\n');
	std::cout << "Press any button to continue..." << std::flush;
	std::cin.get();
}
