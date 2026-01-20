/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:07:12 by lhenriqu          #+#    #+#             */
/*   Updated: 2026/01/20 16:01:04 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.h"

static void printConversion(char c, int n, float f, double d, std::string err) {
	if (err.find('c') != std::string::npos)
		std::cout << "char: "<< IMPOSSIBLE << std::endl;
	else if (!std::isprint(c))
		std::cout << "char: "<< NON_DISPLAYABLE << std::endl;
	else
		std::cout << "char: \'" << YEL << c << RESET << "\'" << std::endl;
	if (err.find('i') != std::string::npos)
		std::cout << "int: "<< IMPOSSIBLE << std::endl;
	else
		std::cout << "int: " << YEL << n << RESET << std::endl;
	if (err.find('f') != std::string::npos)
		std::cout << "float: "<< IMPOSSIBLE << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << "float: " YEL << f << "f" << RESET << std::endl;
	std::cout << "double: " << YEL << d << RESET << std::endl;
}

void toInt(const std::string& literal) {
	long double ld;
	std::stringstream ss(literal);
	ss >> ld;
	std::string err = "";

	if (!checkOverflow(ld, CHAR))
		err = "c";
	
	int n = static_cast<int>(ld);

	char c = static_cast<char>(n);
	float f = static_cast<float>(n);
	double d = static_cast<double>(n);
	printConversion(c, n, f, d, err);
}

void toChar(const std::string& literal) {
	char c = literal[0];
	std::string err = "\0";
	int n = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);
	printConversion(c, n, f, d, err);
}

void toFloat(const std::string& literal) {
	long double ld;
	std::stringstream ss(literal);
	ss >> ld;
	std::string err = "";

	if (!checkOverflow(ld, CHAR))
		err = "c";
	if (!checkOverflow(ld, INT))
		err += "i";
	if (!checkOverflow(ld, DOUBLE))
		err += "f";
	
	float f = static_cast<float>(ld);

	char c = static_cast<char>(f);
	int n = static_cast<int>(f);
	double d = static_cast<double>(f);
	printConversion(c, n, f, d, err);
}

void toDouble(const std::string& literal) {
	long double ld;
	std::stringstream ss(literal);
	ss >> ld;
	std::string err = "";

	if (!checkOverflow(ld, CHAR))
		err = "c";
	if (!checkOverflow(ld, INT))
		err += "i";
	if (!checkOverflow(ld, FLOAT))
		err += "f";
	
	double d = static_cast<double>(ld);

	char c = static_cast<char>(d);
	int n = static_cast<int>(d);
	float f = static_cast<float>(d);
	printConversion(c, n, f, d, err);
	
}

void handlePseudoLiteral(const std::string& literal) {
	std::cout << "char: " << IMPOSSIBLE << std::endl;
	std::cout << "int: " << IMPOSSIBLE << std::endl;
	if (!literal.compare("inff") || !literal.compare("+inff") || !literal.compare("-inff"))
	{
		std::cout << "float: " << YEL + literal + RESET << std::endl;
		std::cout << "double: " << YEL + literal.substr(0, literal.size() - 1) + RESET << std::endl;
	}
	else if (!literal.compare("inf") || !literal.compare("+inf") || !literal.compare("-inf"))
	{
		std::cout << "float: " << IMPOSSIBLE << std::endl;
		std::cout << "double: " << YEL + literal + RESET << std::endl;
	}
	else
	{
		std::cout << "float: " << YEL << "nanf" << RESET << std::endl;
		std::cout << "double: " << YEL << "nan" << RESET << std::endl;
	}
}