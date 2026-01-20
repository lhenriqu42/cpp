/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:42:45 by gangel-a          #+#    #+#             */
/*   Updated: 2026/01/20 18:26:18 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.h"
#include "utils.h"

int main(void) {
	Base *testPTR = generate();
	Base *testREF = generate();
	
	Base &ref = *testREF;

	std::cout << "testPTR: ";
	identify(testPTR);

	std::cout << "testREF: ";
	identify(ref);

	delete testPTR;
	delete testREF;
}