/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:46:01 by gangel-a          #+#    #+#             */
/*   Updated: 2026/01/21 15:14:33 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <exception>
#include "Colors.h"

template <typename T>
class Array
{
  private:
	T *_data;
	unsigned int _size;

  public:
	Array();
	Array(unsigned int n);
	Array(const Array &copy);
	Array &operator=(const Array &other);
	T &operator[](int index);
	const T &operator[](int index) const;
	~Array();

	unsigned int size(void) const;

	class IndexOutOfBounds : public std::exception
	{
		public:
		const char *what() const throw();
	};
};

#include "Array.tpp"