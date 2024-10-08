/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:44:04 by mpitot            #+#    #+#             */
/*   Updated: 2024/10/08 13:34:38 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

#define BLUE "\033[1;34m"
#define DEFAULT "\033[0m"

void	main_ex00()
{
	std::cout << BLUE << "Creation of an undefined animal, a dog and a cat :" << DEFAULT << std::endl;
	// const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << std::endl << std::endl;

	std::cout << BLUE << "Type of the animals :" << DEFAULT << std::endl;
	// std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << BLUE << "The animals making sounds :" << DEFAULT << std::endl;
	// meta->makeSound();
	i->makeSound();
	j->makeSound();
	std::cout << std::endl << std::endl;

	std::cout << BLUE << "Destruction of ALL the animals :" << DEFAULT << std::endl;
	// delete meta;
	delete j;
	delete i;
}

int	main_ex01()
{
	std::cout << BLUE << "Subject main : " << DEFAULT << std::endl;
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	delete j;
	delete i;

	std::cout << std::endl << std::endl;
	return (0);
}

int	array_test()
{
	const size_t array_size = 10;
	Animal *array[array_size];

	std::cout << BLUE << "Filling the array with dogs and cats :" << DEFAULT << std::endl;
	for (size_t i = 0; i < array_size; i++)
	{
		if (i % 2 == 0)
			array[i] = new Dog();
		else
			array[i] = new Cat();
		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl;

	std::cout << BLUE << "The animals in the array making sounds :" << DEFAULT << std::endl;
	for (size_t i = 0; i < array_size; i++)
	{
		array[i]->makeSound();
	}
	std::cout << std::endl << std::endl;

	std::cout << BLUE << "Destruction of the array" << DEFAULT << std::endl;
	for (size_t i = 0; i < array_size; i++)
	{
		delete array[i];
	}
	std::cout << std::endl << std::endl;

	return (0);
}

int	copy_test()
{
	std::cout << BLUE << "Creation of a dog and a cat :" << DEFAULT << std::endl;
	Dog	*dog = new Dog();
	Cat	*cat = new Cat();
	std::cout << std::endl << std::endl;

	std::cout << BLUE << "Copy of the dog and the cat :" << DEFAULT << std::endl;
	Dog	*dog_copy = new Dog(*dog);
	std::cout << std::endl;
	Cat	*cat_copy = new Cat(*cat);
	std::cout << std::endl << std::endl;

	std::cout << BLUE << "The animals making sounds :" << DEFAULT << std::endl;
	cat->makeSound();
	cat_copy->makeSound();
	std::cout << std::endl;
	dog->makeSound();
	dog_copy->makeSound();
	std::cout << std::endl << std::endl;

	std::cout << BLUE << "Destruction of the animals :" << DEFAULT << std::endl;
	delete dog;
	delete cat;
	delete dog_copy;
	delete cat_copy;
	std::cout << std::endl << std::endl;

	return (0);
}

int main()
{
	main_ex00();
	main_ex01();
	array_test();
	copy_test();

	return (0);
}