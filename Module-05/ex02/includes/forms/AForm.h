/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:00:40 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/12/16 21:19:17 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.h"
#include <iostream>
#include <string>

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

class AForm
{
  private:
	AForm();
	const std::string _name;
	const size_t _gradeToSign;
	const size_t _gradeToExecute;
	t_bool _isSigned;

  public:
	// Constructors
	AForm(const std::string &name, size_t gradeToSign, size_t gradeToExecute);
	AForm(const AForm &src);
	AForm &operator=(const AForm &src);
	// Deconstructor
	virtual ~AForm();
	// Getters
	const std::string &getName() const;
	const size_t &getGradeToSign() const;
	const size_t &getGradeToExecute() const;
	const t_bool &getIsSigned() const;

	// Methods
	void beSigned(Bureaucrat &bureaucrat);
	virtual void execute(const Bureaucrat &executor) const = 0;

	class GradeTooHighException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};

	class FormNotSignedException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const AForm &form);
std::ostream &operator<<(std::ostream &os, const AForm *form);