/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 08:41:54 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/09/03 10:26:51 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>
#include "Colors.h"

class Fixed {
	public:
		Fixed();
		~Fixed();
		Fixed(const int input);
		Fixed(const float input);
		Fixed(const Fixed& copy);
		Fixed&	operator=(Fixed const &rSym);
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float toFloat(void)const;
		int toInt(void)const;
	private:
		int					value;
		static const int	bits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);