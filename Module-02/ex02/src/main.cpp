/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 09:09:37 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/09/03 11:06:31 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"


int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a 		<<	GRN 	<< 		"\t\tis a at start\n" 		<< RESET << std::endl;
	std::cout << ++a 	<< 	YEL 	<< 		"\tis a at ++a\n" 			<< RESET << std::endl;
	std::cout << a 		<<	YEL 	<< 		"\tis a after ++a\n" 		<< RESET << std::endl;
	std::cout << a++ 	<< 	CYN		<< 		"\tis a at a++\n" 			<< RESET << std::endl;
	std::cout << a		<<	CYN		<< 		"\tis a after a++\n" 		<< RESET << std::endl;
	std::cout << b 		<<	GRN		<< 		"\t\tvalue of b\n"			<< RESET << std::endl;

	std::cout << Fixed::max(a, b) 	<< 		MAG << "\t\tthe max of a and b\n" 	<< RESET << std::endl;
	std::cout << Fixed::min(a, b) 	<< 		MAG << "\tthe min of a and b\n" 	<< RESET << std::endl;

	return 0;
}
