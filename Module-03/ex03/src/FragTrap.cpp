/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:47:17 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/09/05 10:47:18 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "FragTrap.h"

// Constructors / Destructor
FragTrap::~FragTrap()
{
	std::cout << RED "FragTrap Deconstructor for " RESET << this->_name << RED " called" RESET << std::endl;
}

FragTrap::FragTrap(): ClapTrap()
{
	this->_hit_pts = 100;
	this->_energy_pts = 100;
	this->_attack_dmg = 30;
	std::cout << GRN "FragTrap Default Constructor called" RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy)
{
	std::cout << GRN "FragTrap Copy Constructor called" RESET << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->_hit_pts = 100;
	this->_energy_pts = 100;
	this->_attack_dmg = 30;
	std::cout << GRN "FragTrap Constructor for the name " RESET << this->_name << GRN " called" RESET << std::endl;
}





// Assignment Operator
FragTrap &FragTrap::operator=(const FragTrap &src)
{
	std::cout << YEL "FragTrap Assignation operator called" RESET << std::endl;
	if (this != &src)
		ClapTrap::operator=(src);
	return *this;
}





// Public Methods
void	FragTrap::highFiveGuys(void)
{
	std::cout << CYN "FragTrap " RESET << this->_name << CYN ": You want a high five? " MAG "\n\t*WHAMM*\n" CYN "Here you go." RESET << std::endl;
}