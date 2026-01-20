/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:04:56 by lhenriqu          #+#    #+#             */
/*   Updated: 2026/01/20 18:11:51 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.h"
#include <iostream>

int main(void) {
	Data person = {"Luiz", 23};
	uintptr_t personAddress = Serializer::serialize(&person);

	std::cout << "Original Data address: " << &person << std::endl;
	std::cout << "Deserialized         : " << Serializer::deserialize(personAddress) << std::endl;
}
