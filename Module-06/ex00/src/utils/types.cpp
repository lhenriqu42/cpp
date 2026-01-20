/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:07:06 by lhenriqu          #+#    #+#             */
/*   Updated: 2026/01/20 15:56:20 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.h"

static bool isFloatingPointNumber(const std::string& literal) {
	std::size_t dot_position = literal.find('.');

	if (dot_position == std::string::npos)
		return false;
	if (dot_position == 0 || dot_position == literal.length() - 1)
		return false;
	if (!isdigit(literal[dot_position - 1]) && !isdigit(literal[dot_position + 1]))
		return false;
	for (std::size_t i = 0; i < literal.length(); i++) {
		if (i == 0 && (literal[i] == '+' || literal[i] == '-'))
			i++;
		if (!std::isdigit(literal[i]) && dot_position != i)
			return false;
	}
	return true;
}

bool isInt(const std::string& literal) {
	for (std::size_t i = 0; i < literal.length(); i++) {
		if (i == 0 && (literal[i] == '+' || literal[i] == '-'))
			i++;
		if (!std::isdigit(literal[i]))
			return false;
	}

	long double ld;
	std::stringstream ss(literal);
	ss >> ld;

	if (!checkOverflow(ld, INT))
		return false;
	return true;
}

bool isChar(const std::string& literal) {
	if (literal.length() != 1)
		return false;
	if (!std::isprint(literal[0]))
		return false;
	return true;
}

bool isFloat(const std::string& literal) {
	std::string suffix = literal.substr(literal.length() - 1);
	if (suffix != "f")
		return false;
	std::string without_suffix = literal.substr(0, literal.length() - 1); // Remove 'f' suffix
	if(!isFloatingPointNumber(without_suffix))
		return false;

	long double ld;
	std::stringstream ss(without_suffix);
	ss >> ld;

	if (!checkOverflow(ld, FLOAT))
		return false;
	return true;
}

bool isDouble(const std::string& literal) {
	if(!isFloatingPointNumber(literal))
		return false;

	long double ld;
	std::stringstream ss(literal);
	ss >> ld;
	
	if (!checkOverflow(ld, DOUBLE))
		return false;
	return true;
}

bool isPseudoLiteral(const std::string& literal) {
	return (
			literal == "inf" || literal == "+inf" || literal == "-inf" ||
			literal == "inff" || literal == "+inff" || literal == "-inff" ||
			literal == "nan" || literal == "+nan" || literal == "-nan" ||
			literal == "nanf" || literal == "+nanf" || literal == "-nanf"
		);
}