/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:47:51 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/09/05 10:47:51 by lhenriqu         ###   ########.fr       */
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
