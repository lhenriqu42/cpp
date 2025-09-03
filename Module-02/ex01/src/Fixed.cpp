/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 08:46:01 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/09/03 10:29:12 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

Fixed::Fixed() : value(0) {
	std::cout << GRN << "Default constructor called" << RESET << std::endl;
}

Fixed::~Fixed() {
	std::cout << RED << "Destructor called" << RESET << std::endl;
}

Fixed::Fixed(Fixed const &src) {
	std::cout << GRN << "Copy constructor called" << RESET << std::endl;
	*this = src;
}

Fixed::Fixed(const int input)
{
	std::cout << GRN << "Fixed Int Constructor called" << RESET << std::endl;
	this->value = input << this->bits;
}

Fixed::Fixed(const float input)
{
	std::cout << GRN << "Fixed Float Constructor called" << RESET << std::endl;
	this->value = roundf(input * (1 << this->bits));
}




Fixed&	Fixed::operator=(Fixed const &rSym) {
	std::cout << YEL << "Copy assignement operator called" << RESET << std::endl;
	if (this != &rSym)
		this->value = rSym.getRawBits();
	return *this;
}

int		Fixed::getRawBits() const {
	// std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

void	Fixed::setRawBits(int const raw) {
	this->value = raw;
}

float	Fixed::toFloat(void)const
{
	return ((float)this->value / (float)(1 << this->bits));
}

int	Fixed::toInt(void)const
{
	return (this->value >> this->bits);
}


std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}