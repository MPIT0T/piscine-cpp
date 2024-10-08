/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:44:04 by mpitot            #+#    #+#             */
/*   Updated: 2024/10/07 14:21:57 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

#define BLUE "\033[1;34m"
#define DEFAULT "\033[0m"

int main()
{
	std::cout << BLUE << "Creation of an undefined animal, a dog and a cat :" << DEFAULT << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << std::endl << std::endl;

	std::cout << BLUE << "Type of the animals :" << DEFAULT << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << BLUE << "The animals making sounds :" << DEFAULT << std::endl;
	meta->makeSound();
	i->makeSound();
	j->makeSound();
	std::cout << std::endl << std::endl;

	std::cout << BLUE << "Creation of an undefined wrong animal and a wrong cat :" << DEFAULT << std::endl;
	const WrongAnimal* wrong = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << std::endl << std::endl;

	std::cout << BLUE << "Type of the wrong animals :" << DEFAULT << std::endl;
	std::cout << wrong->getType() << " " << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << BLUE << "The wrong animals making sounds :" << DEFAULT << std::endl;
	wrong->makeSound();
	wrongCat->makeSound();
	std::cout << std::endl << std::endl;

	std::cout << BLUE << "Destruction of ALL the animals :" << DEFAULT << std::endl;
	delete meta;
	delete j;
	delete i;
	delete wrong;
	delete wrongCat;

	return 0;
}