/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:47:09 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/09/05 10:47:09 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "DiamondTrap.h"

// Constructors / Destructor
DiamondTrap::~DiamondTrap()
{
	std::cout << RED "DiamondTrap Deconstructor for " RESET << this->_name << RED " called" RESET << std::endl;
}

DiamondTrap::DiamondTrap(): ClapTrap("defaultDT_clap_trap")
{
	this->_name = "defaultDT";
	this->_hit_pts = FragTrap::_hit_pts;
	this->_energy_pts = ScavTrap::_energy_pts;
	this->_attack_dmg = FragTrap::_attack_dmg;
	std::cout << GRN "DiamondTrap Default Constructor called" RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy): ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	*this = copy;
	std::cout << YEL "DiamondTrap Copy Constructor called" RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_trap")
{
	this->_name = name;
	this->_hit_pts = FragTrap::_hit_pts;
	this->_energy_pts = ScavTrap::_energy_pts;
	this->_attack_dmg = FragTrap::_attack_dmg;
	std::cout << GRN "DiamondTrap Constructor for the name " RESET << this->_name << GRN " called" RESET << std::endl;
}





// Overloaded Operators
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src)
{
	std::cout << "DiamondTrap Assignation operator called" << std::endl;
	if (this != &src)
	{
		ClapTrap::operator=(src);
		this->_name = src._name + "_clap_trap";
	}
	return *this;
}





// Public Methods
void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << MAG "Hello i am a DiamondTrap named " RESET << this->_name << MAG
	" and i am originated from the ClapTrap named " RESET << ClapTrap::_name << MAG "." RESET
	<< std::endl;
}