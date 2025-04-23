/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:08:17 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/04/23 11:56:24 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.h"

HumanB::HumanB(std::string name) : _name(name)
{
	this->_weapon = NULL;
	std::cout << C_BLU << this->_name<< C_RST <<" joined the battlefield " C_RED "unarmed" C_RST " to fight. 😲" << std::endl;
}

HumanB::~HumanB(void)
{
    std::cout << C_BLU << this->_name<< C_RST << C_RED " died. 💀" C_RST << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
	std::cout << C_BLU << this->_name<< C_RST << " grabbed a " << C_GRN << this->_weapon->getType() << C_RST << " to fight with." << std::endl;
}

void HumanB::attack()
{
	if (this->_weapon)
		std::cout << C_BLU << this->_name << C_RST << " attacks with his " << C_GRN << this->_weapon->getType() << C_RST << ". 😎" << std::endl;
	else
		std::cout << C_BLU << this->_name << C_RST << " attacks unarmed. 😲" << std::endl;
}

