/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:50:31 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/09/05 10:50:32 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Animal.h"

Animal::~Animal()
{
	std::cout << RED "Animal Deconstructor called" RESET<< std::endl;
}

Animal::Animal():_type("")
{
	std::cout << GRN "Animal Default Constructor called" RESET << std::endl;
}

Animal::Animal(const Animal &copy)
{
	std::cout << YEL "Animal Copy Constructor called" RESET << std::endl;
	*this = copy;
}






Animal &Animal::operator=(const Animal &src)
{
	std::cout << YEL "Animal Assignation operator called" RESET << std::endl;
	if (this != &src)
		this->_type = src._type;
	return *this;
}






void Animal::makeSound(void)const
{
	std::cout << MAG "This animal doesn't make any sound." RESET << std::endl;
}

std::string	Animal::getType(void)const
{
	return (this->_type);
}