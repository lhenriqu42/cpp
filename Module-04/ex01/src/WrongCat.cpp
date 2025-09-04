/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 20:34:08 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/09/03 20:35:45 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.h"

WrongCat::WrongCat() : WrongAnimal() {
	this->_type = "WrongCat";
	std::cout << GRN "WrongCat default constructor called" RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy) {
	std::cout << GRN "WrongCat copy constructor called" RESET << std::endl;
	*this = copy;
}

WrongCat::~WrongCat() {
	std::cout << RED "WrongCat destructor called" RESET << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &src) {
	std::cout << YEL "WrongCat copy assignment operator called" RESET << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

void WrongCat::makeSound(void) const {
	std::cout << "**WrongCat sounds**" << std::endl;
}