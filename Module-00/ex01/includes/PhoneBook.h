/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:33:02 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/04/16 14:06:50 by lhenriqu         ###   ########.fr       */
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

	void getInfo(Contact& current, const std::string& str,  void (Contact::*setter)(const std::string&));
	void getContactDetails(int index);
	std::string trim(const std::string& str);

  public:
	PhoneBook(void);
	~PhoneBook(void);
	// FUNCTIONS
	void add(void);
	void search(void);
	void printMenu(void);
};

#endif
