/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:19:54 by tblaase           #+#    #+#             */
/*   Updated: 2025/09/03 19:00:24 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.h"

// Constructors / Destructor
ScavTrap::~ScavTrap()
{
	std::cout << RED "ScavTrap Deconstructor for " RESET << this->_name << RED " called" RESET << std::endl;
}

ScavTrap::ScavTrap(): ClapTrap()
{
	this->_hit_pts = 100;
	this->_energy_pts = 50;
	this->_attack_dmg = 20;
	this->_guarding_gate = false;
	std::cout << GRN "ScavTrap Default Constructor called" RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy)
{
	this->_guarding_gate = copy._guarding_gate;
	std::cout << YEL "ScavTrap Copy Constructor called" RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->_hit_pts = 100;
	this->_energy_pts = 50;
	this->_attack_dmg = 20;
	this->_guarding_gate = false;
	std::cout << "ScavTrap Constructor for the name " << this->_name << " called" << std::endl;
}





// Assignment Operator
ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	std::cout << YEL "ScavTrap Assignation operator called" RESET << std::endl;
	if (this != &src)
	{
		ClapTrap::operator=(src);
		this->_guarding_gate = src._guarding_gate;
	}
	return *this;
}





// Public Methods
void	ScavTrap::attack(const std::string &target)
{
	if (this->_hit_pts == 0)
	{
		std::cout << RED "ScavTrap " RESET << this->_name << RED " is not able to attack " YEL << target << RED ", because he has no " GRN "HP" RED " left." RESET << std::endl;
		return ;
	}

	if (this->_energy_pts == 0)
	{
		std::cout << RED  "ScavTrap " RESET << this->_name << RED " is not able to attack " YEL << target << RED ", because he has no energy points left." RESET << std::endl;
		return ;
	}

	std::cout << GRN "ScavTrap " RESET << this->_name << GRN " attacks " YEL << target << GRN ", causing " RED << this->_attack_dmg << GRN " points of damage!" RESET << std::endl;
	this->_energy_pts--;
}

void	ScavTrap::guardGate(void)
{
	if (this->_guarding_gate)
	{
		std::cout << RED "ScavTrap " RESET << this->_name << RED " is already guarding the gate." RESET << std::endl;
		return ;
	}

	this->_guarding_gate = true;
	std::cout << GRN "ScavTrap " RESET << this->_name << GRN " is now guarding the gate." RESET << std::endl;
}