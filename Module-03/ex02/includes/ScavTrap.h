/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:49:02 by tblaase           #+#    #+#             */
/*   Updated: 2025/09/03 17:45:19 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.h"


class ScavTrap: public ClapTrap
{
	private:
		bool _guarding_gate;
	public:
		// Orthodox Canonical Form
		ScavTrap();
		~ScavTrap();
		ScavTrap(const ScavTrap &copy);
		ScavTrap(std::string name);
		ScavTrap &operator=(const ScavTrap &src);


		
		// Public Methods
		void attack(const std::string &target);
		void guardGate(void);

};