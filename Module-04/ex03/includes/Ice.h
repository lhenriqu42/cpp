/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:46:28 by ysoroko           #+#    #+#             */
/*   Updated: 2025/09/05 10:35:55 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "AMateria.h"

class Ice : public AMateria
{
	public:
		Ice();
		~Ice();
		Ice(Ice const & ref);
		Ice & operator=(Ice const & ref);
		Ice *clone() const;
		void use(ICharacter& target);
};
