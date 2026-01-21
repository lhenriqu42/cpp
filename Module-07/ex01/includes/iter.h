/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:16:20 by gangel-a          #+#    #+#             */
/*   Updated: 2026/01/21 13:52:31 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <cstdlib>
# include "Colors.h"

template <typename T>
void iter(T* arr, const std::size_t len, void (*func)(T&)) {
	for (std::size_t i = 0; i < len; i++)
		func(arr[i]);
}

template <typename T>
void iter(const T* arr, const std::size_t len, void (*func)(const T&)) {
	for (std::size_t i = 0; i < len; i++)
		func(arr[i]);
}