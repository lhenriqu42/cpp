/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:45:29 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/09/05 10:45:30 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ClapTrap.h"

int main()
{
	std::cout << "### TESTING CLAPTRAP ###\n" << std::endl;
	{
		std::cout << BLU "Constructing" RESET << std::endl;
		ClapTrap a;
		ClapTrap b("Cody");

		std::cout << BLU "Testing" RESET << std::endl;
		a.attack("some other robot");
		a.takeDamage(10);
		a.takeDamage(10);
		a.beRepaired(5);
		a.attack("some other other robot");
		b.beRepaired(3);
		for (int i = 0; i < 12; i++)
			b.attack("Cody-clone");
		b.beRepaired(3);
		std::cout << BLU "Deconstructing" RESET << std::endl;
	}
	return (0);
}