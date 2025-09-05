/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:45:03 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/09/05 10:45:03 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Point.h"
// Deconstructor
Point::~Point() {}





// Constructors
Point::Point(): _x(0), _y(0) {}

Point::Point(const float x, const float y):_x(x), _y(y) {}

Point::Point(const Point &copy): _x(copy.getX()), _y(copy.getY()) {}





// Assignment Operator
Point &Point::operator=(const Point &src)
{
	(void)src;
	return *this;
}





// Getters
const Fixed	&Point::getX(void)const
{
	return (this->_x);
}

const Fixed	&Point::getY(void)const
{
	return (this->_y);
}





// Overload for ostream
std::ostream	&operator<<(std::ostream &o, Point const point)
{
	o	<<	MAG		<<
			"_x: "	<<	RESET	<<	point.getX()
		<<	MAG		<<
			" _y: " << 	RESET	<<	point.getY()
		<< std::endl;
	return (o);
}