#include "RobotomyRequestForm.h"
#include <cstdlib>
int generateRandomNumber(int min, int max)
{
	static t_bool first = TRUE;
	if (first)
	{
		srand(static_cast<unsigned int>(time(NULL)));
		first = FALSE;
	}
	return rand() % (max - min + 1) + min;
}

RobotomyRequestForm::~RobotomyRequestForm() {}
RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", this->_gradeToSign, this->_gradeToExecute), _target(target) {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src), _target(src._target) {}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this != &src) AForm::operator=(src);
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (this->getIsSigned() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << YEL "Brrrrr... Brrrrr... " RESET << std::endl;
	if (generateRandomNumber(0, 1))
		std::cout << this->_target << GRN " has been robotomized successfully." RESET << std::endl;
	else
		std::cout << this->_target << RED " robotomy failed." RESET << std::endl;
};