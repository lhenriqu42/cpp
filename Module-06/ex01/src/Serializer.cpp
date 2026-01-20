/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:04:24 by gangel-a          #+#    #+#             */
/*   Updated: 2026/01/20 18:05:39 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.h"

Serializer::Serializer(){}

Serializer::Serializer(const Serializer& copy){
	*this = copy;
}

Serializer& Serializer::operator=(const Serializer& other){
	if (this != &other)
		return *this;
	return *this;
}

Serializer::~Serializer(){}

uintptr_t Serializer::serialize(Data* ptr){
	uintptr_t ret = reinterpret_cast<uintptr_t>(ptr); 
	return ret;
}

Data* Serializer::deserialize(uintptr_t raw){
	Data* ret = reinterpret_cast<Data*>(raw);
	return ret;
}
