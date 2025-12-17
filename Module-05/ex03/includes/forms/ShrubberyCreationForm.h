#pragma once
#include "AForm.h"
#include <fstream>
class ShrubberyCreationForm : public AForm
{
  private:
	ShrubberyCreationForm();
	const std::string _target;
	static const size_t _gradeToSign = 145;
	static const size_t _gradeToExecute = 137;

  public:
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &src);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
	void execute(const Bureaucrat &executor) const;
};