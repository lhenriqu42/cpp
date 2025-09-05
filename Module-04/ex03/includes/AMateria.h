/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:40:47 by ysoroko           #+#    #+#             */
/*   Updated: 2025/09/05 10:25:57 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include "ICharacter.h"
# include "Colors.h"

class ICharacter;

class AMateria
{
	private:
		AMateria();
		
	protected:
		const std::string	_type;
		
	public:
		AMateria(std::string const & type);
		virtual ~AMateria();
		AMateria(AMateria const & ref);

		virtual std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};