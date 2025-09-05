/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:47:43 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/09/05 10:47:43 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#pragma once

#include "Animal.h"


class Cat: public Animal
{
	private:

	public:
		Cat();
		Cat(const Cat &copy);
		~Cat();

		
		Cat &operator=(const Cat &src);

		void makeSound(void)const;

};
