/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 18:24:52 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/12/17 12:01:22 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.h"
#include "Bureaucrat.h"
#include "Intern.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>

size_t randomNumber(int min, int max)
{
	static t_bool first = TRUE;
	if (first)
	{
		srand(static_cast<unsigned int>(time(NULL)));
		first = FALSE;
	}
	return rand() % (max - min + 1) + min;
}

int	main(void)
{
	{
		std::cout << BLU "Constructing" RESET << std::endl;

		Bureaucrat *president = new Bureaucrat("President", 1);
		Bureaucrat *vice = new Bureaucrat("Vice-President", 2);
		Bureaucrat *ceo = new Bureaucrat("CEO", 10);
		Bureaucrat *manager = new Bureaucrat("Manager", 70);
		Bureaucrat *trainee = new Bureaucrat("trainee", 150);
		std::cout << std::endl;

		std::vector<Bureaucrat*> bureaucrats;
		bureaucrats.push_back(president);
		bureaucrats.push_back(vice);
		bureaucrats.push_back(ceo);
		bureaucrats.push_back(manager);
		bureaucrats.push_back(trainee);


		const std::string forms[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
		size_t const num_valid_forms = 3;

		for (size_t i = 0; i < num_valid_forms; i++)
		{
			std::cout << std::endl;
			std::cout << BLU << "----------------------------------------------------------------------" << RESET << std::endl;
			std::cout << std::endl;
			Intern someRandomIntern;
			AForm* form = NULL;
			try
			{
				size_t form_index = randomNumber(0, 2);
				size_t bureaucrat_sign_index = randomNumber(0, bureaucrats.size() - 1);
				size_t bureaucrat_execute_index = randomNumber(0, bureaucrats.size() - 1);
				std::ostringstream oss;
				oss << "Target_" << (i + 1);
				form = someRandomIntern.makeForm(forms[form_index], oss.str());
				std::cout << *form << std::endl;
				
				std::cout << std::endl;
				bureaucrats[bureaucrat_sign_index]->signForm(*form);
				bureaucrats[bureaucrat_execute_index]->executeForm(*form);
			}
			catch (const std::exception& e)
			{
				std::cerr << RED "Exception: " << e.what() << RESET << std::endl;
			}
			delete form;
		}

		std::cout << std::endl;
		std::cout << BLU << "----------------------------------------------------------------------" << RESET << std::endl;
		std::cout << std::endl;

		std::cout << BLU "Destructing" RESET << std::endl;
		for (size_t i = 0; i < bureaucrats.size(); i++)
		{
			delete bureaucrats[i];
		}
	}
}