/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 09:47:42 by tblaase           #+#    #+#             */
/*   Updated: 2025/09/04 11:22:18 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "WrongAnimal.h"
#include "WrongCat.h"
#include "Brain.h"

int main()
{
	std::cout << BLU "Constructing" RESET << std::endl;
	const Animal	*meta[10];
	for (int i = 0; i < 10; i++)
	{
		if (i % 2)
			meta[i] = new Cat();
		else
			meta[i] = new Dog();
	}
	std::cout << std::endl;

	std::cout << BLU "Testing" RESET << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << std::endl;
		std::cout << "Animal _type: " << meta[i]->getType() << std::endl;
		meta[i]->makeSound();
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << BLU "Deconstructing" RESET << std::endl;
	for (int i = 0; i < 10; i++)
		delete(meta[i]);

//THIS PART IS FOR TESTING DEEP COPY ↓

	std::cout << std::endl << std::endl;
	std::cout << "#### showing that the copy constructor creates a deep copy ####" << std::endl;
	std::cout << std::endl;

	std::cout << BLU "Constructing" RESET << std::endl;
	Dog *a = new Dog();
	// Cat *a = new Cat();

	a->getBrain()->setIdea(0, "I have to sniff it");
	a->getBrain()->setIdea(1, "I have to pee on it");
	a->getBrain()->setIdea(2, "I have to sniff it again");
	a->getBrain()->setIdea(101, "some shit");

	Dog *b = new Dog(*a);
	// Cat *b = new Cat(*a);
	std::cout << std::endl;

	std::cout << BLU "Testing a" RESET << std::endl;
	std::cout << "The " << a->getType() << " a has the following ideas: " << std::endl;
	a->getBrain()->printIdeas(3);
	std::cout << std::endl;

	std::cout << BLU "Deconstructing a" RESET << std::endl;
	delete(a);
	std::cout << std::endl;

	std::cout << BLU "Testing b" RESET << std::endl;
	std::cout << "The " << b->getType() << " b has the following ideas: " << std::endl;
	b->getBrain()->printIdeas(3);
	std::cout << std::endl;

	std::cout << BLU "Deconstructing b" RESET << std::endl;
	delete(b);

	return (0);
}