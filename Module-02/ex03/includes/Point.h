/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:02:31 by tblaase           #+#    #+#             */
/*   Updated: 2025/09/03 11:11:41 by lhenriqu         ###   ########.fr       */
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