/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 09:47:42 by tblaase           #+#    #+#             */
/*   Updated: 2025/09/03 20:37:43 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "WrongAnimal.h"
#include "WrongCat.h"

int main()
{
	std::cout << BLU "Constructing" RESET << std::endl;
	const Animal	*meta = new Animal();
	std::cout << std::endl;
	std::cout << BLU "Testing" RESET << std::endl;

	std::cout << "Animal _type: " << meta->getType() << std::endl;
	meta->makeSound();
	std::cout << std::endl;

	std::cout << BLU "Deconstructing" RESET << std::endl;
	delete meta;
	std::cout << std::endl;

	std::cout << "-------------------------------------------------------" << std::endl;

	std::cout << std::endl;
	std::cout << BLU "Constructing" RESET << std::endl;
	const Animal	*cat = new Cat();
	std::cout << std::endl;

	std::cout << BLU "Testing" RESET << std::endl;
	std::cout << "Cat _type: " << cat->getType() << std::endl;
	cat->makeSound();
	std::cout << std::endl;

	std::cout << BLU "Deconstructing" RESET << std::endl;
	delete cat;
	std::cout << std::endl;

	std::cout << "-------------------------------------------------------" << std::endl;

	std::cout << std::endl;
	std::cout << BLU "Constructing" RESET << std::endl;
	const Animal	*doggo = new Dog();
	std::cout << std::endl;
	std::cout << BLU "Testing" RESET << std::endl;
	std::cout << "Dog _type: " << doggo->getType() <<std::endl;
	doggo->makeSound();
	std::cout << std::endl;
	std::cout << BLU "Deconstructing" RESET << std::endl;
	delete doggo;
	std::cout << std::endl;

	std::cout << "-------------------------------------------------------" << std::endl;

	std::cout << std::endl;
	std::cout << BLU "Constructing" RESET << std::endl;
	const WrongAnimal	*wrong_meta = new WrongAnimal();
	std::cout << std::endl;

	std::cout << BLU "Testing" RESET << std::endl;
	std::cout << "Animal _type: " << wrong_meta->getType() << std::endl;
	wrong_meta->makeSound();
	std::cout << std::endl;

	std::cout << BLU "Deconstructing" RESET << std::endl;
	delete wrong_meta;
	std::cout << std::endl;

	std::cout << "-------------------------------------------------------" << std::endl;

	std::cout << BLU "Constructing" RESET << std::endl;
	const WrongAnimal	*wrong_catto = new WrongCat();
	std::cout << std::endl;

	std::cout << BLU "Testing" RESET << std::endl;
	std::cout << "WrongCat _type: " << wrong_catto->getType() <<std::endl;
	wrong_catto->makeSound();
	std::cout << std::endl;

	std::cout << BLU "Deconstructing" RESET << std::endl;
	delete wrong_catto;
	std::cout << std::endl;

	std::cout << "-------------------------------------------------------" << std::endl;

	std::cout << BLU "Constructing" RESET << std::endl;
	const WrongCat	*wrong_catta = new WrongCat();
	std::cout << std::endl;

	std::cout << BLU "Testing" RESET << std::endl;
	std::cout << "WrongCat _type: " << wrong_catta->getType() <<std::endl;
	wrong_catta->makeSound();
	std::cout << std::endl;

	std::cout << BLU "Deconstructing" RESET << std::endl;
	delete wrong_catta;
	std::cout << std::endl;

	return (0);
}