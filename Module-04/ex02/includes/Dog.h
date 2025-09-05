/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:50:19 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/09/05 10:50:19 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#pragma once

#include "Animal.h"
#include "Brain.h"

class Dog: public Animal
{
	private:
		Brain *_brain;

	public:
		Dog();
		Dog(const Dog &copy);
		~Dog();


		Dog &operator=(const Dog &src);

		void makeSound(void)const;
		Brain *getBrain(void)const;
		
};
