/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:33:02 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/04/15 18:47:49 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.h"

class PhoneBook
{
  private:
	Contact		_list[8];
	size_t	_index;

	void get_info(Contact& current, const std::string& str,  void (Contact::*setter)(const std::string&));
	std::string trim(const std::string& str);

  public:
	PhoneBook(void);
	~PhoneBook(void);
	// FUNCTIONS
	void add(void);
	void search(void);
};

#endif
