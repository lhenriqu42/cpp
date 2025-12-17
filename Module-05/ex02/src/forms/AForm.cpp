/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:15:57 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/12/16 18:22:03 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.h"

AForm::AForm(const std::string& name, size_t gradeToSign, size_t gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _isSigned(FALSE)
{
	std::cout << GRN "AForm Parameterized Constructor called" RESET << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& src) : _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute), _isSigned(src._isSigned)
{
	std::cout << GRN "AForm Copy Constructor called" RESET << std::endl;
}

AForm& AForm::operator=(const AForm& src)
{
	std::cout << GRN "AForm Assignment Operator called" RESET << std::endl;
	if (this != &src)
	{
		// Since all members are const, we cannot assign them.
	}
	return *this;
}

AForm::~AForm()
{
	std::cout << RED "AForm Deconstructor for " RESET << _name << RED  " called" RESET << std::endl;
}




const std::string& AForm::getName() const
{
	return _name;
}

const size_t& AForm::getGradeToSign() const
{
	return  _gradeToSign;
}

const size_t& AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

const t_bool &AForm::getIsSigned() const
{
	return _isSigned;
}


void AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	this->_isSigned = TRUE;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& Aform)
{
	os << "AForm Name: " MAG << Aform.getName() << RESET << ", Signed: " << (Aform.getIsSigned() == TRUE ? GRN "Yes" RESET : RED "No" RESET);
	os << ", Grade to Sign: " BLU << Aform.getGradeToSign() << RESET << ", Grade to Execute: " BLU << Aform.getGradeToExecute() << RESET;
	os << std::endl;
	return os;
}

std::ostream& operator<<(std::ostream& os, const AForm* Aform)
{
	os << "AForm Name: " MAG << Aform->getName() << RESET << ", Signed: " << (Aform->getIsSigned() == TRUE ? GRN "Yes" RESET : RED "No" RESET);
	os << ", Grade to Sign: " BLU << Aform->getGradeToSign() << RESET << ", Grade to Execute: " BLU << Aform->getGradeToExecute() << RESET;
	os << std::endl;
	return os;
}