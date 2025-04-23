/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 08:41:54 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/04/23 09:32:27 by lhenriqu         ###   ########.fr       */
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
	Zombie();
	~Zombie(void);
	
	void announce(void);
	void setName(std::string &name);
};

Zombie*	zombieHorde( int N, std::string name );

#endif