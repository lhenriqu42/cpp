/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 09:09:37 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/09/03 10:30:36 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"


int main(void)
{
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);

	a = Fixed(1234.4321f);

	std::cout << CYN << "a is " << RESET << a << std::endl;
	std::cout << CYN << "b is " << RESET << b << std::endl;
	std::cout << CYN << "c is " << RESET << c << std::endl;
	std::cout << CYN << "d is " << RESET << d << std::endl;

	std::cout << CYN << "a is " << RESET << a.toInt() << CYN <<" as integer" << RESET << std::endl;
	std::cout << CYN << "b is " << RESET << b.toInt() << CYN <<" as integer" << RESET << std::endl;
	std::cout << CYN << "c is " << RESET << c.toInt() << CYN <<" as integer" << RESET << std::endl;
	std::cout << CYN << "d is " << RESET << d.toInt() << CYN <<" as integer" << RESET << std::endl;

	return 0;
}
