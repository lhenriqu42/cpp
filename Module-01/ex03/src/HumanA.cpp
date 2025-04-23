/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:08:17 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/04/23 11:58:52 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.h"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) 
{
	std::cout << C_BLU << this->_name<< C_RST << " joined the battlefield and grabbed a " << C_GRN << this->_weapon.getType() << C_RST << " to fight." << std::endl;
}

HumanA::~HumanA(void)
{
    std::cout << C_BLU << this->_name<< C_RST << C_RED " died. 💀" C_RST << std::endl;
}

void HumanA::attack()
{
	std::cout << C_BLU << this->_name<< C_RST << " attacks with his " << C_GRN << this->_weapon.getType() << C_RST << "." << std::endl;
}

