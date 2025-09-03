/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:43:17 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/09/03 19:47:11 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ScavTrap.h"
#include "FragTrap.h"


class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string _name;
	public:
		// Orthodox Canonical Form
		DiamondTrap();
		~DiamondTrap();
		DiamondTrap(const DiamondTrap &copy);
		DiamondTrap(std::string name);
		DiamondTrap &operator=(const DiamondTrap &src);

		// Public Methods
		void attack(const std::string &target);
		void whoAmI(void);

};