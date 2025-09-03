/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:51:14 by tblaase           #+#    #+#             */
/*   Updated: 2025/09/03 20:23:21 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.h"


class Dog: public Animal
{
	private:

	public:
		Dog();
		Dog(const Dog &copy);
		~Dog();


		Dog &operator=(const Dog &src);

		void makeSound(void)const;
		
};
