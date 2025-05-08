/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:14:33 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/05/08 19:42:05 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

Harl::Harl(void)
{
	std::cout << C_BLU << "A wild Harl has appeared!" << C_RST << std::endl;
}

Harl::~Harl(void)
{
	std::cout << C_BLU << "Wild Harl flew away!" << C_RST << std::endl;
}

void Harl::debug(void)
{
	std::cout << C_PUR << "[DEBUG]   " << C_RST;
	std::cout << "I love to get extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger.";
	std::cout << " I just love it!" << std::endl;
}

void Harl::info(void)
{
	std::cout << C_CYA << "[INFO]    " << C_RST;
	std::cout << "I cannot believe adding extra bacon cost more money.";
	std::cout << " You don’t put enough! If you did I would not have to ask";
	std::cout << " for it!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << C_YEL << "[WARNING] " << C_RST;
	std::cout << "I think I deserve to have some extra bacon for free.";
	std::cout << " I’ve been coming here for years and you just started ";
	std::cout << "working here last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << C_RED << "[ERROR]   " << C_RST;
	std::cout << "This is unacceptable, I want to speak to the manager now.";
	std::cout << std::endl;
}

int Harl::get_index(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			return (i);
		}
	}
	return (-1);
}

void Harl::complain(std::string level)
{
	int	i;
	void (Harl::*fun[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	i = Harl::get_index(level);
	if (i != -1)
		while (i < static_cast<int>(sizeof(fun) / sizeof(fun[0])))
		{
			(this->*fun[i])();
			i++;
		}
	else
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
