/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:07:10 by lhenriqu          #+#    #+#             */
/*   Updated: 2026/01/20 15:07:10 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.h"

bool checkOverflow(long double ld, t_type type) {
	switch (type) {
		case CHAR:
			if (ld < 0 || ld > 127)
				return false;
			break;
		case INT:
			if (ld > std::numeric_limits<int>::max() || ld < std::numeric_limits<int>::min()) 
				return false;
			break;
		case FLOAT:
			if (ld > std::numeric_limits<float>::max() || ld < -std::numeric_limits<float>::max())
				return false;
			break;
		case DOUBLE:
			if (ld > std::numeric_limits<double>::max() || ld < -std::numeric_limits<double>::max())
				return false;
			break;
		default:
			return false;
			break;
	}

	return true;
}