/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:46:54 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/09/05 10:46:55 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#pragma once

#include "ClapTrap.h"


class FragTrap: virtual public ClapTrap
{
	private:

	public:
		// Orthodox Canonical Form
		FragTrap();
		virtual ~FragTrap();
		FragTrap(const FragTrap &copy);
		FragTrap(std::string name);
		FragTrap &operator=(const FragTrap &src);



		// Public Methods
		void highFiveGuys(void);

};