/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 08:46:01 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/09/03 10:51:16 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

// Destructor
Fixed::~Fixed() {
}





// Constructors
Fixed::Fixed() : value(0) {
}

Fixed::Fixed(Fixed const &src) {
	*this = src;
}

Fixed::Fixed(const int input)
{
	this->value = input << this->bits;
}

Fixed::Fixed(const float input)
{
	this->value = roundf(input * (1 << this->bits));
}





// Copy assignment operator
Fixed&	Fixed::operator=(Fixed const &rSym) {
	if (this != &rSym)
		this->value = rSym.getRawBits();
	return *this;
}





// Overloaded Comparison Operators
bool	Fixed::operator>(Fixed fixed) const
{
	return (this->toFloat() > fixed.toFloat());
}

bool	Fixed::operator<(Fixed fixed) const
{
	return (this->toFloat() < fixed.toFloat());
}

bool	Fixed::operator>=(Fixed fixed) const
{
	return (this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator<=(Fixed fixed) const
{
	return (this->toFloat() <= fixed.toFloat());
}

bool	Fixed::operator==(Fixed fixed) const
{
	return (this->toFloat() == fixed.toFloat());
}

bool	Fixed::operator!=(Fixed fixed) const
{
	return (this->toFloat() != fixed.toFloat());
}





// Overloaded Arithmetic Operators
float	Fixed::operator+(Fixed fixed) const
{
	return (this->toFloat() + fixed.toFloat());
}

float	Fixed::operator-(Fixed fixed) const
{
	return (this->toFloat() - fixed.toFloat());
}

float	Fixed::operator*(Fixed fixed) const
{
	return (this->toFloat() * fixed.toFloat());
}

float	Fixed::operator/(Fixed fixed) const
{
	return (this->toFloat() / fixed.toFloat());
}





// Overloaded pre-increment Operators
Fixed	Fixed::operator++()
{
	this->value++;
	return (*this);
}

Fixed	Fixed::operator--()
{
	this->value--;
	return (*this);
}

// Overloaded post-increment Operators
Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;
	++this->value;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;
	--this->value;
	return (tmp);
}





// Min / Max
Fixed	&Fixed::min(Fixed &first, Fixed &second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}

const Fixed	&Fixed::min(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}

Fixed	&Fixed::max(Fixed &first, Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
}

const Fixed	&Fixed::max(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
}





// Getter / Setter
int		Fixed::getRawBits() const {
	// std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

void	Fixed::setRawBits(int const raw) {
	this->value = raw;
}





// Conversions
float	Fixed::toFloat(void)const
{
	return ((float)this->value / (float)(1 << this->bits));
}

int	Fixed::toInt(void)const
{
	return (this->value >> this->bits);
}





// Stream insertion operator
std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}