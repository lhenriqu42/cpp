/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:46:58 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/09/05 10:46:58 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#pragma once

#include "ClapTrap.h"


class ScavTrap: virtual public ClapTrap
{
	private:
		bool _guarding_gate;
	public:
		// Orthodox Canonical Form
		ScavTrap();
		virtual ~ScavTrap();
		ScavTrap(const ScavTrap &copy);
		ScavTrap(std::string name);
		ScavTrap &operator=(const ScavTrap &src);


		
		// Public Methods
		void attack(const std::string &target);
		void guardGate(void);

};