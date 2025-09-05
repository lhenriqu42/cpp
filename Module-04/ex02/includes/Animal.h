/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:50:05 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/09/05 10:50:05 by lhenriqu         ###   ########.fr       */
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
		Animal();

	public:
		Animal(const Animal &copy);
		virtual ~Animal();


		// Overloaded Operator
		Animal &operator=(const Animal &src);

	
		// Public Methods
		virtual void makeSound(void)const;
	
		// Getter
		std::string getType(void)const;

};
