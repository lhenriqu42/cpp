/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:15:54 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/09/05 10:36:37 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.h"

Ice::~Ice()
{
	std::cout << CYN << this->_type << RED " destroyed." RESET << std::endl;
}

Ice::Ice() : AMateria("ice")
{
	std::cout << CYN << this->_type << GRN " constructed." RESET << std::endl;
}

Ice::Ice(Ice const & ref) : AMateria(ref)
{
	std::cout << CYN << this->_type << YEL " constructed from copy." RESET << std::endl;
}

Ice & Ice::operator=(Ice const & ref)
{
	std::cout << YEL "Assigned from " CYN << ref.getType() << YEL "." RESET << std::endl;
	return (*this);
}

Ice* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << BLU "* shoots an ice bolt at " RESET << target.getName() << BLU " *" RESET << std::endl;
}