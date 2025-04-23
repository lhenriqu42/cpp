/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 09:47:42 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/04/23 09:53:54 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

# define C_GRN "\001\033[32m\002"
# define C_RST "\001\033[0m\002"


int main()
{
	 std::string s1 = "HI THIS IS BRAIN";
	 std::string *stringPTR = &s1;
	 std::string &stringREF = s1;
	 std::cout << "Address of string s1: " << C_GRN << &s1 << C_RST << std::endl;
	 std::cout << "Address held by stringPTR: " << C_GRN << stringPTR << C_RST << std::endl;
	 std::cout << "Address held by stringREF: " << C_GRN << &stringREF << C_RST << std::endl;
	 std::cout << "----------------------------------------" << std::endl;
	 std::cout << "Value of string s1: " << C_GRN << s1 << C_RST << std::endl;
	 std::cout << "Value pointed to by stringPTR: " << C_GRN << *stringPTR << C_RST << std::endl;
	 std::cout << "Value pointed to by stringREF: " << C_GRN << stringREF << C_RST << std::endl;
	return (0);
}