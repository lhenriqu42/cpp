/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:13:09 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/12/16 12:08:14 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Colors.h"
#include <iostream>

class Bureaucrat
{
  private:
	const std::string _name;
	size_t _grade;
	// Setter
	void setGrade(int grade);

  public:
	// Constructors
	Bureaucrat();
	Bureaucrat(const Bureaucrat &src);
	Bureaucrat(int grade);
	Bureaucrat(const std::string name);
	Bureaucrat(const std::string name, int grade);
	Bureaucrat &operator=(const Bureaucrat &src);
	// Deconstructor
	~Bureaucrat();
	// Getters
	const std::string getName(void) const;
	size_t getGrade(void) const;
	// Methods
	void incrementGrade(void);
	void decrementGrade(void);
	void signForm(class Form &form);

	// Exceptions
	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};
};

// ostream Overload
std::ostream &operator<<(std::ostream &o, const Bureaucrat &a);
std::ostream &operator<<(std::ostream &o, const Bureaucrat *a);
