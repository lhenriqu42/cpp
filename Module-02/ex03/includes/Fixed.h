/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 08:41:54 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/09/03 10:40:59 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>
#include "Colors.h"

class Fixed
{
public:
	// Orthodox Canonical Form
	Fixed();
	~Fixed();
	Fixed(const int input);
	Fixed(const float input);
	Fixed(const Fixed &copy);
	Fixed &operator=(Fixed const &rSym);

	// Comparison Operators
	bool operator>(Fixed fixed) const;
	bool operator<(Fixed fixed) const;
	bool operator>=(Fixed fixed) const;
	bool operator<=(Fixed fixed) const;
	bool operator==(Fixed fixed) const;
	bool operator!=(Fixed fixed) const;

	// Arithmetic Operators
	float operator+(Fixed fixed) const;
	float operator-(Fixed fixed) const;
	float operator*(Fixed fixed) const;
	float operator/(Fixed fixed) const;

	// pre-increment Operators
	Fixed operator++();
	Fixed operator--();
	// post-increment Operators
	Fixed operator++(int);
	Fixed operator--(int);

	// Convert
	float toFloat(void) const;
	int toInt(void) const;

	// Min/Max
	static Fixed &min(Fixed &first, Fixed &second);
	static const Fixed &min(Fixed const &first, Fixed const &second);
	static Fixed &max(Fixed &first, Fixed &second);
	static const Fixed &max(Fixed const &first, const Fixed &second);

	// Getter
	int getRawBits(void) const;
	// Setter
	void setRawBits(int const raw);

private:
	int value;
	static const int bits = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);