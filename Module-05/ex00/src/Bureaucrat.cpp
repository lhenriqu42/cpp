/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 18:24:49 by lhenriqu          #+#    #+#             */
/*   Updated: 2026/01/20 09:55:12 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

// Constructors
Bureaucrat::Bureaucrat(void) : _name("default"), _grade(150)
{
	std::cout << GRN "Bureaucrat Default Constructor called for " RESET << this->getName() << GRN " with grade of " RESET << this->getGrade() << std::endl;
}
Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src.getName())
{
	std::cout << GRN "Bureaucrat Copy Constructor called to copy " RESET << src.getName() << GRN " into " RESET << this->getName() << std::endl;
	*this = src;
}
Bureaucrat::Bureaucrat(int grade) : _name("default")
{
	std::cout << GRN "Bureaucrat Grade Constructor called for " RESET << this->getName() << GRN " with grade of " RESET << grade << std::endl;
	this->setGrade(grade);
}
Bureaucrat::Bureaucrat(const std::string name) : _name(name), _grade(150)
{
	std::cout << GRN "Bureaucrat Name Constructor called for " RESET << this->getName() << GRN " with grade of " RESET << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	std::cout << GRN "Bureaucrat Name and Grade Constructor called for " RESET << this->getName() << GRN " with grade of " RESET << grade << std::endl;
	this->setGrade(grade);
}

// Deconstructor
Bureaucrat::~Bureaucrat()
{
	std::cout << RED "Bureaucrat Deconstructor for " RESET << this->getName() << RED " called" << RESET << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	std::cout << YEL "Assignation operator called for " MAG << this->_name << RESET << std::endl;
	if (this == &src)
		return (*this);
	this->_grade = src.getGrade();
	return (*this);
}

// Public Methods
void Bureaucrat::incrementGrade(void)
{
	std::cout << CYN "Trying to increment grade of " RESET << this->getName() << std::endl;
	this->setGrade(this->_grade - 1);
}

void Bureaucrat::decrementGrade(void)
{
	std::cout << CYN "Trying to decrement grade of " RESET << this->getName() << std::endl;
	this->setGrade(this->_grade + 1);
}

// Getters
const std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

size_t Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

// Setters
void Bureaucrat::setGrade(int grade)
{
	if (grade > 150) throw Bureaucrat::GradeTooLowException();
	if (grade < 1) throw Bureaucrat::GradeTooHighException();
	this->_grade = grade;
}

// Exceptions
const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};

// Overload of the << operator
std::ostream &operator<<(std::ostream &o, const Bureaucrat &a)
{
	o << MAG << a.getName() << RESET ",  bureaucrat grade " << CYN << a.getGrade() << RESET << std::endl;
	return (o);
}
std::ostream &operator<<(std::ostream &o, const Bureaucrat *a)
{
	o << MAG << a->getName() << RESET ",  bureaucrat grade " << CYN << a->getGrade() << RESET << std::endl;
	return (o);
}