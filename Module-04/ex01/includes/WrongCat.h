/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:49:16 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/09/05 10:49:16 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#pragma once

#include "WrongAnimal.h"


class WrongCat: public WrongAnimal
{
	private:

	public:
		WrongCat();
		WrongCat(const WrongCat &copy);


		~WrongCat();

		WrongCat &operator=(const WrongCat &src);

		void makeSound(void)const;

};