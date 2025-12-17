#pragma once
#include "AForm.h"
#include <exception>
#include <string>

class Intern
{
  public:
	Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	~Intern();

	AForm *makeForm(std::string formName, std::string target);

	class FormNotFoundException : public std::exception
	{
		public:
		const char *what() const throw();
	};
};