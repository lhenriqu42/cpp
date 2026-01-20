/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:07:03 by lhenriqu          #+#    #+#             */
/*   Updated: 2026/01/20 16:05:22 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.h"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) {
	*this = copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	if (this != &other)
		return *this;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal) {
	if (literal.empty())
	{
		std::cout << RED "Error:" RESET " Empty string provided" << std::endl;
		return;
	}
	if (isPseudoLiteral(literal))
		return handlePseudoLiteral(literal);
	if (isFloat(literal))
		return toFloat(literal);
	 if (isInt(literal))
		return toInt(literal);
	 if (isDouble(literal))
		return toDouble(literal);
	 if (isChar(literal))
		return toChar(literal);
	std::cout << "Error: Impossible to print or input not convertable" << std::endl;
	return;
}
