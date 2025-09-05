/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:36:49 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/09/05 10:38:35 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.h"

Cure::Cure() : AMateria("cure")
{
	std::cout << CYN << this->_type << GRN " created." RESET << std::endl;
}

Cure::~Cure()
{
	std::cout << CYN << this->_type << RED " destroyed." RESET << std::endl;
}

Cure::Cure(Cure const & ref) : AMateria(ref)
{
	std::cout << CYN << this->_type << YEL " constructed from copy." RESET << std::endl;
}

Cure & Cure::operator=(Cure const & ref)
{
	std::cout << YEL "Assigned from " CYN << ref.getType() << YEL "." RESET << std::endl;
	return (*this);
}

Cure* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << BLU "* heals " RESET << target.getName() << BLU "’s wounds *" RESET << std::endl;
}