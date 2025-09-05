/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:50:35 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/09/05 10:50:36 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Brain.h"

Brain::~Brain()
{
	std::cout << RED "Brain Deconstructor called" RESET << std::endl;
}

Brain::Brain()
{
	std::cout << GRN "Brain Default Constructor called" RESET << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << YEL "Brain Copy Constructor called" RESET << std::endl;
	*this = copy;
}

Brain &Brain::operator=(const Brain &src)
{
	std::cout << YEL "Brain Assignation operator called" RESET << std::endl;
	if (this != &src)
	{
		for (int i = 0; i < 100; ++i)
		{
			if (!src._ideas[i].empty())
				this->_ideas[i] = src._ideas[i];
		}
	}
	return *this;
}

void Brain::printIdeas(size_t limit) const
{
	if (limit > 100)
		limit = 100;
	for (size_t i = 0; i < limit; i++)
			std::cout << MAG "\tIdea " RESET << i << MAG " of the Cat is: \"" YEL << this->getIdea(i) << MAG "\" at the address " CYN << this->getIdeaAddress(i) << MAG "." RESET << std::endl;
}

// Getter
const std::string Brain::getIdea(size_t i) const
{
	if (i < 100)
		return (this->_ideas[i]);
	else
		return ( RED "There is only 100 ideas per brain." RESET);
}

const std::string *Brain::getIdeaAddress(size_t i) const
{
	return (i < 100) ? &this->_ideas[i] : NULL;
}

// Setter
void Brain::setIdea(size_t i, std::string idea)
{
	if (i < 100)
		this->_ideas[i] = idea;
	else
		std::cout << RED "There is only 100 ideas per brain." RESET << std::endl;
}