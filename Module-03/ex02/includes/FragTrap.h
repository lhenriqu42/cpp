/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:46:11 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/09/05 10:46:11 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#pragma once

#include "ClapTrap.h"


class FragTrap: public ClapTrap
{
	private:

	public:
		// Orthodox Canonical Form
		FragTrap();
		~FragTrap();
		FragTrap(const FragTrap &copy);
		FragTrap(std::string name);
		FragTrap &operator=(const FragTrap &src);



		// Public Methods
		void highFiveGuys(void);

};