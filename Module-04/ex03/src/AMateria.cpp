/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:23:37 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/09/05 10:29:45 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.h"

AMateria::~AMateria()
{
	std::cout << RED "Abstract Materia destroyed." RESET << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << GRN "Abstract Materia constructed." RESET << std::endl;
}

AMateria::AMateria(AMateria const & ref) : _type(ref._type)
{
	std::cout << YEL "Abstract Materia copy constructed." RESET << std::endl;
}

std::string const & AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << MAG "Abstract Materia used on " RESET << target.getName() << MAG "." RESET << std::endl;
}