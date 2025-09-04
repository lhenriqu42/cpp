/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 20:32:00 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/09/03 20:34:04 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.h"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << GRN "WrongAnimal default constructor called" RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << GRN "WrongAnimal copy constructor called" RESET << std::endl;
	*this = copy;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << RED "WrongAnimal destructor called" RESET << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
	std::cout << YEL "WrongAnimal copy assignment operator called" RESET << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "**WrongAnimal sounds**" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (this->_type);
}