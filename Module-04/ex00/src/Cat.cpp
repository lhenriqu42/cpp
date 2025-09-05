/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:48:20 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/09/05 10:48:21 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Cat.h"

Cat::~Cat()
{
	std::cout << RED "Cat Deconstructor called" RESET << std::endl;
}

Cat::Cat(): Animal()
{
	this->_type = "Cat";
	std::cout << GRN "Cat Default Constructor called" RESET << std::endl;
}

Cat::Cat(const Cat &copy): Animal()
{
	std::cout << YEL "Cat Copy Constructor called" RESET << std::endl;
	*this = copy;
}

Cat &Cat::operator=(const Cat &src)
{
	std::cout << YEL "Cat Assignation operator called" RESET << std::endl;
	if (this != &src)
		this->_type = src._type;
	return *this;
}

void	Cat::makeSound(void)const
{
	std::cout << this->getType() << " says: **Meeeoow**" << std::endl;
}