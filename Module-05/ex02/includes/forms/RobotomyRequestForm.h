#pragma once
#include "AForm.h"

class RobotomyRequestForm : public AForm
{
  private:
	RobotomyRequestForm();
	const std::string _target;
	static const size_t _gradeToSign = 72;
	static const size_t _gradeToExecute = 45;

  public:
	~RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm &src);
	RobotomyRequestForm& operator=(const RobotomyRequestForm &src);
	void execute(const Bureaucrat& executor) const;
};