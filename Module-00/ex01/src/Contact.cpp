/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:30:29 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/04/15 17:48:59 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.h"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

std::string	Contact::get_fname(void) const
{
	return (this->_fname);
}

std::string	Contact::get_lname(void) const
{
	return (this->_lname);
}

std::string	Contact::get_nick(void) const
{
	return (this->_nick);
}

std::string	Contact::get_phone_num(void) const
{
	return (this->_phone_num);
}

std::string	Contact::get_secret(void) const
{
	return (this->_secret);
}

void	Contact::set_fname(const std::string& str)
{
	this->_fname = str;
}

void	Contact::set_lname(const std::string& str)
{
	this->_lname = str;
}

void	Contact::set_nick(const std::string& str)
{
	this->_nick = str;
}

void	Contact::set_phone_num(const std::string& str)
{
	this->_phone_num = str;
}

void	Contact::set_secret(const std::string& str)
{
	this->_secret = str;
}
