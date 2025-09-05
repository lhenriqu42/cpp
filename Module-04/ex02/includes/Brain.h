/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:50:11 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/09/05 10:50:11 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#pragma once

#include <string>
#include <iostream>
#include "Colors.h"


class Brain
{
	private:
		std::string _ideas[100];

	public:
		Brain();
		~Brain();
		Brain(const Brain &copy);
		Brain &operator=(const Brain &src);

		void printIdeas(size_t limit) const;
		
		// Getter
		const std::string getIdea(size_t i)const;
		const std::string *getIdeaAddress(size_t i)const;
		
		// Setter
		void setIdea(size_t i, std::string idea);
};