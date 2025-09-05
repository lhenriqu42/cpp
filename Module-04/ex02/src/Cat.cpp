/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:50:39 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/09/05 10:50:39 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Cat.h"

Cat::~Cat()
{
	std::cout << RED "Cat Deconstructor called" RESET << std::endl;
	delete this->_brain;
}

Cat::Cat(): Animal()
{
	this->_type = "Cat";
	this->_brain = new Brain();
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
	{
		this->_type = src._type;
		this->_brain = new Brain(*src._brain);
	}
	return *this;
}

void	Cat::makeSound(void)const
{
	std::cout << this->getType() << " says: **Meeeoow**" << std::endl;
}

Brain	*Cat::getBrain(void)const
{
	return this->_brain;
}