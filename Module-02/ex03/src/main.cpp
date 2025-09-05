/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:44:54 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/09/05 10:44:55 by lhenriqu         ###   ########.fr       */
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