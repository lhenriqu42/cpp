/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:41:57 by tblaase           #+#    #+#             */
/*   Updated: 2025/09/03 20:23:29 by lhenriqu         ###   ########.fr       */
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
