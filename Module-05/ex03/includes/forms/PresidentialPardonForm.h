#pragma once
#include "AForm.h"

class PresidentialPardonForm : public AForm
{
  private:
	PresidentialPardonForm();
	const std::string _target;
	static const size_t _gradeToSign = 25;
	static const size_t _gradeToExecute = 5;

  public:
	~PresidentialPardonForm();
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &src);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
	void execute(const Bureaucrat &executor) const;
};