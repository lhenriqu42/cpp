/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:51:07 by gangel-a          #+#    #+#             */
/*   Updated: 2026/01/21 13:48:55 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.h"

int main( void ) {
	int a = 2;
	int b = 3;

	::swap( a, b );
	
	std::cout << MAG "int " RESET "a " MAG "= " BLU << a << RESET ", " MAG "int" RESET " b " MAG "= " BLU << b << RESET << std::endl;
	std::cout << GRN "min" MAG "(" RESET "a, b" MAG ") " RESET "= " BLU << ::min( a, b ) << RESET << std::endl;
	std::cout << GRN "max" MAG "(" RESET "a, b" MAG ") " RESET "= " BLU << ::max( a, b ) << RESET << std::endl;


	std::cout << std::endl;
	std::cout << MAG "---------------------------------------------------------------------" RESET << std::endl;
	std::cout << std::endl;
	
	
	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);

	std::cout << "c " MAG "= " YEL "\"" << c << RESET "\", d " MAG "= " YEL "\"" << d << "\"" RESET << std::endl;
	std::cout << GRN "min" MAG "(" RESET "c, d" MAG ") " RESET "= " YEL "\"" << ::min( c, d ) << "\"" RESET << std::endl;
	std::cout << GRN "max" MAG "(" RESET "c, d" MAG ") " RESET "= " YEL "\"" << ::max( c, d ) << "\"" RESET << std::endl;


	
	return 0;
}