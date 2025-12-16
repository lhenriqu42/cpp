/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:15:57 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/12/16 14:46:46 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.h"

Form::Form(const std::string& name, size_t gradeToSign, size_t gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _isSigned(FALSE)
{
	std::cout << GRN "Form Parameterized Constructor called" RESET << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& src) : _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute), _isSigned(src._isSigned)
{
	std::cout << GRN "Form Copy Constructor called" RESET << std::endl;
}

Form& Form::operator=(const Form& src)
{
	std::cout << GRN "Form Assignment Operator called" RESET << std::endl;
	if (this != &src)
	{
		// Since all members are const, we cannot assign them.
	}
	return *this;
}

Form::~Form()
{
	std::cout << RED "Form Deconstructor for " RESET << _name << RED  " called" RESET << std::endl;
}




const std::string& Form::getName() const
{
	return _name;
}

const size_t& Form::getGradeToSign() const
{
	return  _gradeToSign;
}

const size_t& Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

const t_bool &Form::getIsSigned() const
{
	return _isSigned;
}


void Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	this->_isSigned = TRUE;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form Name: " MAG << form.getName() << RESET << ", Signed: " << (form.getIsSigned() == TRUE ? GRN "Yes" RESET : RED "No" RESET);
	os << ", Grade to Sign: " BLU << form.getGradeToSign() << RESET << ", Grade to Execute: " BLU << form.getGradeToExecute() << RESET;
	os << std::endl;
	return os;
}

std::ostream& operator<<(std::ostream& os, const Form* form)
{
	os << "Form Name: " MAG << form->getName() << RESET << ", Signed: " << (form->getIsSigned() == TRUE ? GRN "Yes" RESET : RED "No" RESET);
	os << ", Grade to Sign: " BLU << form->getGradeToSign() << RESET << ", Grade to Execute: " BLU << form->getGradeToExecute() << RESET;
	os << std::endl;
	return os;
}