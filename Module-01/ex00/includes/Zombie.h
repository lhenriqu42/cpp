/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 08:41:54 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/04/23 09:06:01 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>

class Zombie
{
  private:
	std::string _name;

  public:
	Zombie(std::string name);
	~Zombie(void);
	
	void announce(void);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif