/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 08:46:01 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/09/03 10:25:21 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

Fixed::Fixed() : value(0) {
	std::cout << GRN << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(Fixed const &src) {
	std::cout << YEL << "Copy constructor called" << RESET << std::endl;
	*this = src;
}

Fixed::~Fixed() {
	std::cout << RED << "Destructor called" << RESET << std::endl;
}

Fixed&	Fixed::operator=(Fixed const &rSym) {
	std::cout << YEL << "Copy assignement operator called" << RESET << std::endl;
	this->value = rSym.getRawBits();
	return *this;
}

int		Fixed::getRawBits() const {
	std::cout << CYN << "getRawBits member function called" << RESET << std::endl;
	return this->value;
}

void	Fixed::setRawBits(int const raw) {
	this->value = raw;
}
