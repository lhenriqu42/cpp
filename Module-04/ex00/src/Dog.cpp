/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 20:30:14 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/09/03 20:30:58 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.h"

Dog::~Dog()
{
	std::cout << RED "Dog Deconstructor called" RESET << std::endl;
}

Dog::Dog(): Animal()
{
	this->_type = "Dog";
	std::cout << GRN "Dog Default Constructor called" RESET << std::endl;
}

Dog::Dog(const Dog &copy): Animal()
{
	std::cout << YEL "Dog Copy Constructor called" RESET << std::endl;
	*this = copy;
}

Dog &Dog::operator=(const Dog &src)
{
	std::cout << YEL "Dog Assignation operator called" RESET << std::endl;
	if (this != &src)
		this->_type = src._type;
	return *this;
}

void	Dog::makeSound(void)const
{
	std::cout << this->getType() << " says: **Woof Woof**" << std::endl;
}