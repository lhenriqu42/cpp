#include "PresidentialPardonForm.h"

PresidentialPardonForm::~PresidentialPardonForm() {}
PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", this->_gradeToSign, this->_gradeToExecute), _target(target) {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src), _target(src._target) {}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	if (this != &src) AForm::operator=(src);
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (this->getIsSigned() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << this->_target << MAG " has been pardoned by Zaphod Beeblebrox." RESET << std::endl;
}