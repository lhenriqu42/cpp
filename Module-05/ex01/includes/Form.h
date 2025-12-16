/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:00:40 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/12/16 14:46:09 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include "Bureaucrat.h"

typedef enum e_bool { FALSE, TRUE } t_bool;

class Form
{
	private:
		Form();
		const std::string _name;
		const size_t _gradeToSign;
		const size_t _gradeToExecute;
		t_bool _isSigned;
	public:
		// Constructors
		Form(const std::string& name, size_t gradeToSign, size_t gradeToExecute);
		Form(const Form& src);
		Form& operator=(const Form& src);
		// Deconstructor
		~Form();
		// Getters
		const std::string& getName() const;
		const size_t& getGradeToSign() const;
		const size_t& getGradeToExecute() const;
		const t_bool& getIsSigned() const;

		// Methods
		void beSigned(Bureaucrat& bureaucrat);
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Form& form);
std::ostream& operator<<(std::ostream& os, const Form* form);