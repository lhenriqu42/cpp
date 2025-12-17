#include "Intern.h"
#include "AForm.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"
#include <iostream>

Intern::Intern() { std::cout << GRN "Intern created" RESET<< std::endl; }
Intern::Intern(const Intern& other) { *this = other; }
Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}
Intern::~Intern() { std::cout << RED "Intern destroyed" RESET<< std::endl; }

static AForm	*makePresident(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm	*makeRobot(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*makeShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeForm(const std::string formName, const std::string target)
{
	AForm *(*all_forms[])(const std::string target) = {&makePresident, &makeRobot, &makeShrubbery};
	const std::string forms[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

	for (int i = 0; i < 3; i++)
	{
		if (formName == forms[i])
		{
			std::cout << "Intern" GRN " creates " MAG << formName << RESET << std::endl;
			return (all_forms[i](target));
		}
	}

	throw FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const throw()
{
	return ("Form not found");
}