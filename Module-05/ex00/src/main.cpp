/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 18:24:52 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/12/15 18:48:46 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

int	main(void)
{


	
	{
		std::cout << BLU "Constructing" RESET << std::endl;
		Bureaucrat a = Bureaucrat();
		std::cout << std::endl;

		std::cout << BLU "Testing" RESET << std::endl;
		std::cout << a;
		try
		{
			a.incrementGrade();
			a.incrementGrade();
			std::cout << a;
			while(1)
				a.decrementGrade();
		}
		catch (std::exception &e)
		{
			std::cerr << RED "Incrementing grade of " << a.getName() << " failed: " << e.what() << RESET << std::endl;
		}

		std::cout << a;

		std::cout << BLU "Deconstructing" RESET << std::endl;
		std::cout << std::endl;
	}








	




	std::cout << "-------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;
		std::cout << BLU "Constructing" RESET << std::endl;
		Bureaucrat *a = new Bureaucrat(1);
		std::cout << std::endl;
		std::cout << BLU "Testing" RESET << std::endl;
		std::cout << a;

		try
		{
			a->decrementGrade();
		}
		catch (std::exception &e)
		{
			std::cerr << RED "Decrementing grade of " << a->getName() << " failed: " << e.what() << RESET << std::endl;
		}

		std::cout << a;

		try
		{
			a->incrementGrade();
		}
		catch (std::exception &e)
		{
			std::cerr << RED "Incrementing grade of " << a->getName() << " failed: " << e.what() << RESET << std::endl;
		}

		std::cout << a;
		std::cout << std::endl;

		std::cout << BLU "Deconstructing" RESET << std::endl;
		delete a;
		std::cout << std::endl;
	}













	
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;
		std::cout << BLU "Constructing" RESET << std::endl;
		Bureaucrat *a = NULL;

		try
		{
			a = new Bureaucrat(0);
		}
		catch (std::exception &e)
		{
			std::cerr << RED "Constructing default failed: " << e.what() << RESET << std::endl;
		}

		if (a != NULL)
		{
			std::cout << std::endl;

			std::cout << BLU "Deconstructing" RESET << std::endl;
			delete a;
		}

		std::cout << std::endl;
	}












	
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;
		std::cout << BLU "Constructing" RESET << std::endl;
		Bureaucrat *a = NULL;

		try
		{
			a = new Bureaucrat(160);
		}
		catch (std::exception &e)
		{
			std::cerr << RED "Constructing default failed: " << e.what() << RESET << std::endl;
		}

		if (a != NULL)
		{
			std::cout << std::endl;
			std::cout << BLU "Deconstructing" RESET << std::endl;
			delete a;
		}
		std::cout << std::endl;
	}












	
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;
		std::cout << BLU "Constructing" RESET << std::endl;
		Bureaucrat *a = new Bureaucrat("Peter", 120);
		std::cout << std::endl;

		std::cout << BLU "Testing a" RESET << std::endl;
		std::cout << a;

		a->decrementGrade();

		std::cout << a;
		std::cout << std::endl;

		std::cout << BLU "Constructing b" RESET << std::endl;
		Bureaucrat *b = new Bureaucrat(*a);
		std::cout << std::endl;

		std::cout << BLU "Deconstructing a" RESET << std::endl;
		delete a;
		std::cout << std::endl;

		std::cout << BLU "Testing b" RESET << std::endl;
		std::cout << b;
		b->decrementGrade();
		std::cout << b;
		std::cout << std::endl;

		std::cout << BLU "Deconstructing b" RESET << std::endl;
		delete b;

		std::cout << std::endl;
	}
}