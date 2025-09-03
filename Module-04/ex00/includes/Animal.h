/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:24:26 by tblaase           #+#    #+#             */
/*   Updated: 2025/09/03 20:25:40 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "Colors.h"

class Animal
{
	protected:
		std::string _type;

	public:
		Animal();
		Animal(const Animal &copy);
		virtual ~Animal();


		// Overloaded Operator
		Animal &operator=(const Animal &src);

	
		// Public Methods
		virtual void makeSound(void)const;
	
		// Getter
		std::string getType(void)const;

};
