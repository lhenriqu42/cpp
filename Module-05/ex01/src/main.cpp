/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 18:24:52 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/12/16 14:56:23 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"
#include "Form.h"

int	main(void)
{
	{
		std::cout << BLU "Constructing" RESET << std::endl;

		Bureaucrat a = Bureaucrat("Luiz", 50);
		std::cout << a;
		std::cout << std::endl;


		Form form1 = Form("Form1", 50, 100);
		std::cout << form1;
		std::cout << std::endl;


		Form *form2 = new Form("Form2", 1, 100);
		std::cout << form2;
		std::cout << std::endl;


		Form form3 = form1;
		std::cout << form3;
		std::cout << std::endl;


		try {
			Form form4 = Form("Form4", 151, 100);
		} catch (std::exception &e) {
			// Must return GradeTooLowException
			std::cerr << RED "Constructing form4 failed: " RESET << e.what() << std::endl;
		}
		
		try {
			Form form5 = Form("Form5", 0, 100);
		} catch (std::exception &e) {
			// Must return GradeTooHighException
			std::cerr << RED "Constructing form5 failed: " RESET << e.what() << std::endl;
		}







		std::cout << std::endl << std::endl;
		std::cout << BLU "Testing" RESET << std::endl;

		// grade a = 50
		// form1 gradeToSign = 50
		a.signForm(form1); // Should succeed
		a.decrementGrade(); // a = 51
		a.signForm(form3); // Should fail
		std::cout << a << std::endl;
		std::cout << form1 << std::endl;
		std::cout << form3 << std::endl;
		std::cout << std::endl;



		Bureaucrat b = Bureaucrat("Carlos", 1);
		a = b;

		std::cout << std::endl;
		std::cout << a << std::endl;
		a.signForm(*form2); // Should succeed
		std::cout << form2 << std::endl;
		std::cout << std::endl;





		std::cout << BLU "Destructing" RESET << std::endl;
		delete form2;
	}
}