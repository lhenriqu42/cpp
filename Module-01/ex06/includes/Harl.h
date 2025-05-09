/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:14:35 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/05/09 17:28:51 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include <iostream>

class Harl
{
  private:
	static int get_index(std::string level);
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

  public:
	Harl();
	~Harl();
	void complain(std::string level);
};
