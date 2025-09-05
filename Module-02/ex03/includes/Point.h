/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:44:30 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/09/05 10:44:30 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#pragma once

#include <string>
#include <iostream>
#include "Fixed.h"

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;

	public:
		// Orthodox Canonical Form
		Point();
		~Point();
		Point(const float x, const float y);
		Point(const Point& copy);
		Point &operator=(const Point &src);

		// Getters
		const Fixed &getX(void)const;
		const Fixed &getY(void)const;

};

// Overload for ostream
std::ostream	&operator<<(std::ostream &o, Point const point);