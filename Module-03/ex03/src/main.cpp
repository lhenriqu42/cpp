/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:47:21 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/09/05 10:47:21 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "DiamondTrap.h"

int main()
{
	std::cout << "\n\n### TESTING DIAMONDTRAP ###\n" << std::endl;
	{
		std::cout << BLU "Constructing" RESET << std::endl;
		DiamondTrap a;
		DiamondTrap b("Giga Chadd");
		DiamondTrap c(a);

		std::cout << BLU "Testing" RESET << std::endl;
		a.whoAmI();
		a.attack("some super random dude");
		b.whoAmI();
		b.attack("Chadd-clone");
		c.whoAmI();
		std::cout << BLU "Deconstructing" RESET << std::endl;
	}
	return (0);
}