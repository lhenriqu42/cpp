/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:08:12 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/04/23 11:37:25 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <iostream>

# define C_GRN "\001\033[32m\002"
# define C_BLU "\001\033[34m\002"
# define C_RED "\001\033[31m\002"
# define C_RST "\001\033[0m\002"


class Weapon
{
  private:
	std::string _type;

  public:
	Weapon(std::string type);
	~Weapon();
	const std::string &getType() const;
	void setType(std::string type);
	
};

#endif