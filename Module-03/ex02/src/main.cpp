/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:33:55 by tblaase           #+#    #+#             */
/*   Updated: 2025/09/03 19:38:08 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.h"

int main()
{
	std::cout << "\n\n### TESTING FRAGTRAP ###\n" << std::endl;
	{
		std::cout << BLU "Constructing" RESET << std::endl;
		FragTrap e;
		FragTrap f("Chadd");

		std::cout << BLU "Testing" RESET << std::endl;
		e.highFiveGuys();
		e.attack("some random dude");
		e.takeDamage(101);
		e.takeDamage(1);
		e.attack("some random dude");
		f.highFiveGuys();
		// for(int i = 0; i < 101; i++)
		// 	f.attack("FragTrap-clone");
		std::cout << BLU "Deconstructing" RESET << std::endl;
	}
	return (0);
}