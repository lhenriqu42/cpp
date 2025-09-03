/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:57:29 by tblaase           #+#    #+#             */
/*   Updated: 2025/09/03 13:39:22 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.h"

bool bsp(const Point a, const Point b, const Point c, const Point point);

int main(void)
{
	{
		const Point a;
		const Point b(10, -1);
		const Point c(0, 10);
		const Point point(1, 1);

		if (bsp(a, b, c, point) == true)
			std::cout << GRN << "TRUE" << RESET << std::endl;
		else
			std::cout << RED << "FALSE" << RESET << std::endl;
	}
	std::cout << "\n---------------------------------------------------------------------\n" << std::endl;
	{
		Point a(-2.5, -1.5);
		Point b(2, 3);
		Point c(2, -2);
		Point point(4.5, -5);

		if (bsp(a, b, c, point) == true)
			std::cout << GRN << "TRUE" << RESET << std::endl;
		else
			std::cout << RED << "FALSE" << RESET << std::endl;
	}
	return (0);
}