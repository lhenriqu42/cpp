/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:27:18 by tblaase           #+#    #+#             */
/*   Updated: 2025/09/03 19:12:44 by lhenriqu         ###   ########.fr       */
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