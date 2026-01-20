/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:23:19 by lhenriqu          #+#    #+#             */
/*   Updated: 2026/01/20 18:23:29 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Base.h"
# include "A.h"
# include "B.h"
# include "C.h"
# include <string>
# include <cstdlib>
# include <ctime>
# include <iostream>

Base* createA(void);
Base* createB(void);
Base* createC(void);
	
Base * generate(void);
void identify(Base* p);
void identify(Base& p);
