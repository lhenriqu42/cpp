/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:36:12 by lsilva-x          #+#    #+#             */
/*   Updated: 2026/01/20 17:02:29 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.h"

void	test_inf(void)
{
	//------------------INF---------------
	std::cout << MAG << "---------INF---------" << RESET << std::endl;
	
	std::cout << BLU << "inf" << RESET << std::endl;
	ScalarConverter::convert("inf");
	std::cout << std::endl;

	std::cout << BLU << "+inf" << RESET << std::endl;
	ScalarConverter::convert("+inf");
	std::cout << std::endl;

	std::cout << BLU << "-inf" << RESET << std::endl;
	ScalarConverter::convert("-inf");
	std::cout << std::endl;
}

void	test_inff(void)
{
	//------------------INFF---------------
	std::cout << MAG << "---------INFF---------" << RESET << std::endl;

	std::cout << BLU << "inff" << RESET << std::endl;
	ScalarConverter::convert("inff");
	std::cout << std::endl;

	std::cout << BLU << "+inff" << RESET << std::endl;
	ScalarConverter::convert("+inff");
	std::cout << std::endl;

	std::cout << BLU << "-inff" << RESET << std::endl;
	ScalarConverter::convert("-inff");
	std::cout << std::endl;
}

void	test_nan(void)
{
	//------------------NAN---------------
	std::cout << MAG << "---------NAN---------" << RESET << std::endl;
	
	std::cout << BLU << "nan" << RESET << std::endl;
	ScalarConverter::convert("nan");
	std::cout << std::endl;
	
	std::cout << BLU << "+nan" << RESET << std::endl;
	ScalarConverter::convert("+nan");
	std::cout << std::endl;

	std::cout << BLU << "-nan" << RESET << std::endl;
	ScalarConverter::convert("-nan");
	std::cout << std::endl;
}

void	test_nanf(void)
{
	//------------------NANF---------------
	std::cout << MAG << "---------NANF---------" << RESET << std::endl;
	std::cout << BLU << "nanf" << RESET << std::endl;
	ScalarConverter::convert("nanf");
	std::cout << std::endl;

	std::cout << BLU << "+nanf" << RESET << std::endl;
	ScalarConverter::convert("+nanf");
	std::cout << std::endl;

	std::cout << BLU << "-nanf" << RESET << std::endl;
	ScalarConverter::convert("-nanf");
}

void	test_char(void)
{
	//------------------CHAR---------------
	std::cout << MAG << "---------CHAR---------" << RESET << std::endl;
	std::cout << BLU << "a" << RESET << std::endl;
	ScalarConverter::convert("a");
	std::cout << std::endl;

	std::cout << BLU << "\'a\'" << RESET << std::endl;
	ScalarConverter::convert("\'a\'");
	std::cout << std::endl;

	std::cout << BLU << "." << RESET << std::endl;
	ScalarConverter::convert(".");
	std::cout << std::endl;
}

void	test_int(void)
{
	//------------------INTEGER---------------
	std::cout << MAG << "---------INTEGER---------" << RESET << std::endl;
	std::cout << BLU << "42" << RESET << std::endl;
	ScalarConverter::convert("42");
	std::cout << std::endl;

	std::cout << BLU << "67" << RESET << std::endl;
	ScalarConverter::convert("67");
	std::cout << std::endl;

	std::cout << BLU << "0" << RESET << std::endl;
	ScalarConverter::convert("0");
	std::cout << std::endl;

	std::cout << BLU << "-123" << RESET << std::endl;
	ScalarConverter::convert("-123");
	std::cout << std::endl;

	std::cout << BLU << "2147483647" << RESET << std::endl; // INT_MAX
	ScalarConverter::convert("2147483647");
	std::cout << std::endl;

	std::cout << BLU << "-2147483648" << RESET << std::endl; // INT_MIN
	ScalarConverter::convert("-2147483648");
	std::cout << std::endl;

	std::cout << BLU << "  123  " << RESET << std::endl; // Leading/trailing spaces
	ScalarConverter::convert("  123  ");
	std::cout << std::endl;

	std::cout << BLU << "+456" << RESET << std::endl; // Explicit plus sign
	ScalarConverter::convert("+456");
	std::cout << std::endl;

	std::cout << BLU << "-456" << RESET << std::endl; // Explicit plus sign
	ScalarConverter::convert("-456");
	std::cout << std::endl;

	std::cout << BLU << "12abc34" << RESET << std::endl; // Invalid integer input
	ScalarConverter::convert("12abc34");
	std::cout << std::endl;

	std::cout << BLU << "-0" << RESET << std::endl; // Negative zero
	ScalarConverter::convert("-0");
	std::cout << std::endl;
}

void	test_float(void)
{
	//------------------FLOAT---------------
	std::cout << MAG << "---------FLOAT---------" << RESET << std::endl;

	std::cout << BLU << "1.23456789f" << RESET << std::endl;
	ScalarConverter::convert("1.23456789f");
	std::cout << std::endl;

	std::cout << BLU << "3.402823538123214124512512123f" << RESET << std::endl;
	ScalarConverter::convert("3.402823538123214124512512123f");
	std::cout << std::endl;
}

void	test_double(void)
{
	//------------------DOUBLE---------------
	std::cout << MAG << "---------DOUBLE---------" << RESET << std::endl;

	std::cout << BLU << "-3.4028235388971893172893218937218931232198" << RESET << std::endl;
	ScalarConverter::convert("-3.4028235388971893172893218937218931232198");
	std::cout << std::endl;

	std::cout << BLU << "1.79769313486231572121213213123123124124512512521" << RESET << std::endl;
	ScalarConverter::convert("1.79769313486231572121213213123123124124512512521");
	std::cout << std::endl;

		std::cout << BLU << "-1.797693134862315712312831279837218937129873891273891279831" << RESET << std::endl;
	ScalarConverter::convert("-1.797693134862315712312831279837218937129873891273891279831");
	std::cout << std::endl;
}

void	test_string(void)
{
	//------------------STRING---------------
	std::cout << MAG << "---------STRING---------" << RESET << std::endl;

	std::cout << BLU << "hello" << RESET << std::endl;
	ScalarConverter::convert("hello");
	std::cout << std::endl;

	std::cout << BLU << "" << RESET << std::endl; // Empty string
	ScalarConverter::convert("");
	std::cout << std::endl;

	std::cout << BLU << "123abc" << RESET << std::endl; // Alphanumeric string
	ScalarConverter::convert("123abc");
	std::cout << std::endl;

	std::cout << BLU << "!!@@##" << RESET << std::endl; // Special characters
	ScalarConverter::convert("!!@@##");
	std::cout << std::endl;

	std::cout << BLU << "abc" << RESET << std::endl; // Non-numeric string
	ScalarConverter::convert("abc");
	std::cout << std::endl;

	std::cout << BLU << "a1" << RESET << std::endl; // Non-numeric string
	ScalarConverter::convert("a1");
	std::cout << std::endl;
}

void	test_battery(void)
{
	test_inf();
	test_inff();
	test_nan();
	test_nanf();
	test_char();
	test_int();
	test_float();
	test_double();
	test_string();
}

int main(int argc, const char *argv[])
{
	if (argc == 2)
		ScalarConverter::convert(argv[1]);
	if (argc == 1)
		test_battery();
	if (argc > 2)
		std::cerr << RED << "Error: Too many arguments." << RESET << std::endl;
	return (0);
}