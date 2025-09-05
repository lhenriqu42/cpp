/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:46:15 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/09/05 10:46:15 by lhenriqu         ###   ########.fr       */
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