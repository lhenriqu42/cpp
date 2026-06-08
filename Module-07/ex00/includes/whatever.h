/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:52:11 by lhenriqu          #+#    #+#             */
/*   Updated: 2026/01/21 13:38:08 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Colors.h"
template <typename T>
void swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
const T& min (const T& a, const T& b) {
	if (b <= a)
		return b;
	return a;
}

template <typename T>
const T& max (const T& a, const T& b) {
	if (b >= a)
		return b;
	return a;
}