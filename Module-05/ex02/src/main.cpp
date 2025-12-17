/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 18:24:52 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/12/17 11:14:54 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"
#include "AForm.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"
#include <vector>
int	main(void)
{
	{
		std::cout << BLU "Constructing" RESET << std::endl;

		Bureaucrat president("President", 1);
		Bureaucrat vice("Vice-President", 2);
		Bureaucrat ceo("CEO", 10);
		Bureaucrat manager("Manager", 70);
		Bureaucrat intern("Intern", 150);


		AForm *pardonForm = new PresidentialPardonForm("target_to_be_pardoned");	// Necessary grade to sign: 25, execute: 5
		AForm *robotomyForm = new RobotomyRequestForm("target_to_be_robotomized"); 	// Necessary grade to sign: 72, execute: 45
		AForm *shrubberyForm = new ShrubberyCreationForm("target_to_shrubberized");	// Necessary grade to sign: 145, execute: 137


		std::cout << std::endl << std::endl;
		std::cout << BLU "Testing" RESET << std::endl;

		// Errors NOT SIGNED
		std::vector<AForm *> forms_to_test_errors;
		forms_to_test_errors.push_back(pardonForm);
		forms_to_test_errors.push_back(robotomyForm);
		forms_to_test_errors.push_back(shrubberyForm);
		
		for (size_t i = 0; i < forms_to_test_errors.size(); i++)
		{
			president.executeForm(*forms_to_test_errors[i]); // MUST THROW AN ERROR
		}
		std::cout << std::endl << std::endl;


		// Signing forms
		for (size_t i = 0; i < forms_to_test_errors.size(); i++)
		{
			manager.signForm(*forms_to_test_errors[i]); // PARDONFORM SIGN MUST THROW AN ERROR
		}
		
		std::cout << std::endl;
		ceo.signForm(*pardonForm);
		std::cout << std::endl;
		
		// Executing forms
		for (size_t i = 0; i < forms_to_test_errors.size(); i++)
		{
			ceo.executeForm(*forms_to_test_errors[i]); // PARDONFORM EXECUTE MUST THROW AN ERROR
		}

		std::cout << std::endl;
		vice.executeForm(*pardonForm); // MUST WORK
		std::cout << std::endl;



		std::cout << BLU "Destructing" RESET << std::endl;
		delete pardonForm;
		delete robotomyForm;
		delete shrubberyForm;
	}
}