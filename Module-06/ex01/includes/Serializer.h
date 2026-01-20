/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:05:07 by lhenriqu          #+#    #+#             */
/*   Updated: 2026/01/20 18:05:08 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


# include <stdint.h>
# include <iostream>

struct Data {
	std::string name;
	unsigned int age;
};

class Serializer
{
  private:
	Serializer();
	Serializer(const Serializer& copy);
	Serializer& operator=(const Serializer& other);
	~Serializer();

  public:
  // It takes a pointer and converts it to the unsigned integer type uintptr_t
  static uintptr_t serialize(Data* ptr);

  // It takes an unsigned integer parameter and converts it to a pointer to Data
  static Data* deserialize(uintptr_t raw);
};