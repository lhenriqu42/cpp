#include "ShrubberyCreationForm.h"

ShrubberyCreationForm::~ShrubberyCreationForm() {}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", this->_gradeToSign, this->_gradeToExecute), _target(target) {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src), _target(src._target) {}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this != &src) AForm::operator=(src);
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (this->getIsSigned() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::ofstream outfile((this->_target + "_shrubbery").c_str());
	if (!outfile)
	{
		std::cerr << RED "Error: Could not create file." RESET << std::endl;
		return;
	}
	outfile << "       _-_\n"
			   "    /~~   ~~\\\n"
			   " /~~         ~~\\\n"
			   "{               }\n"
			   " \\  _-     -_  /\n"
			   "   ~  \\\\ //  ~\n"
			   "_- -   | | _- _\n"
			   "  _ -  | |   -_\n"
			   "      // \\\\\n";
	outfile.close();
	std::cout << GRN "Shrubbery created at " RESET << this->_target + "_shrubbery" << std::endl;
}