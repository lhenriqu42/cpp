/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 09:52:30 by ysoroko           #+#    #+#             */
/*   Updated: 2025/09/05 10:35:51 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.h"

class Cure : public AMateria
{
	public:
		Cure();
		~Cure();
		Cure(Cure const & ref);
		Cure & operator=(Cure const & ref);
		Cure *clone() const;
		void use(ICharacter& target);
};