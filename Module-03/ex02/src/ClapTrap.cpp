/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:46:22 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/09/05 10:46:22 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ClapTrap.h"


// Constructors / Destructor
ClapTrap::~ClapTrap()
{
	std::cout << RED << "ClapTrap Deconstructor for " << RESET << _name << RED << " called" << RESET << std::endl;
}

ClapTrap::ClapTrap(): _name("default"), _hit_pts(10), _energy_pts(10), _attack_dmg(0)
{
	std::cout << GRN << "ClapTrap Default Constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << YEL << "ClapTrap Copy Constructor called" << RESET << std::endl;
	*this = copy;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hit_pts(10), _energy_pts(10), _attack_dmg(0)
{
	std::cout << GRN << "ClapTrap Constructor for the name " RESET << _name << GRN " called" << RESET << std::endl;
}





// Assignment Operator
ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	//std::cout << "ClapTrap Assignation operator called" << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		this->_hit_pts = src._hit_pts;
		this->_energy_pts = src._energy_pts;
		this->_attack_dmg = src._attack_dmg;
	}
	return *this;
}





// Public Methods
void	ClapTrap::attack(const std::string &target)
{
	if (this->_hit_pts == 0)
	{
		std::cout << RED "ClapTrap " RESET << this->_name << RED " is not able to attack " YEL << target << RED ", because he has no " GRN "HP" RED " left." RESET << std::endl;
		return ;
	}

	if (this->_energy_pts == 0)
	{
		std::cout << RED  "ClapTrap " RESET << this->_name << RED " is not able to attack " YEL << target << RED ", because he has no energy points left." RESET << std::endl;
		return ;
	}

	std::cout << GRN "ClapTrap " RESET << this->_name << GRN " attacks " YEL << target << GRN ", causing " RED << this->_attack_dmg << GRN " points of damage!" RESET << std::endl;
	this->_energy_pts--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_pts == 0)
	{
		std::cout << YEL "ClapTrap " RESET << this->_name << YEL " is already dead, stop beating it." RESET << std::endl;
		return ;
	}
	if (amount > this->_hit_pts)
		this->_hit_pts = 0;
	else
		this->_hit_pts -= amount;
	std::cout << GRN "ClapTrap " RESET << this->_name << GRN " was attacked and lost " RED << amount << GRN " HP, he now has " RESET << this->_hit_pts << GRN " HP." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hit_pts == 0)
	{
		std::cout << RED "ClapTrap " RESET << this->_name << RED " is not able to repair itself, because he doesn't have enough HP." RESET << std::endl;
		return ;
	}

	if (this->_energy_pts == 0){
		std::cout << RED "ClapTrap " RESET << this->_name << RED " is not able to repair itself, because he doesn't have enough energy points." RESET << std::endl;
		return ;
	}

	if ((this->_hit_pts + amount) > 10)
	{
		std::cout << RED "ClapTrap " RESET << this->_name << RED " can't be repaired to have more than 10 HP." RESET << std::endl;
		return ;
	}

	this->_hit_pts += amount;
	std::cout << GRN "ClapTrap " RESET << this->_name << GRN " repaired itself and gained " RESET << amount << GRN " of HP, he now has " RESET << this->_hit_pts << GRN " HP." << std::endl;
	this->_energy_pts--;
}