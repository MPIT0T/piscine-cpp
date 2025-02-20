/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:44:04 by mpitot            #+#    #+#             */
/*   Updated: 2024/10/13 22:43:37 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate(void)
{
	std::srand(std::time(0));
	int randValue = std::rand() % 3;

	if (randValue == 0)
		return new A();
	if (randValue == 1)
		return new B();
	if (randValue == 2)
		return new C();
	return (NULL);
}

void identify(Base *ptr)
{
	if (ptr == NULL)
		std::cout << "NULL pointer" << std::endl;
	else if (dynamic_cast<A *>(ptr))
		std::cout << "type A" << std::endl;
	else if (dynamic_cast<B *>(ptr))
		std::cout << "type B" << std::endl;
	else if (dynamic_cast<C *>(ptr))
		std::cout << "type C" << std::endl;
	else
		std::cout << "tf are you doing man" << std::endl;
}

void identify(Base &ref)
{
	try
	{
		static_cast<void>(dynamic_cast<A &>(ref));
		std::cout << "type A" << std::endl;
		return ;
	}
	catch (std::exception &e) {}

	try
	{
		static_cast<void>(dynamic_cast<B &>(ref));
		std::cout << "type B" << std::endl;
		return ;
	}
	catch (std::exception &e) {}

	try
	{
		static_cast<void>(dynamic_cast<C &>(ref));
		std::cout << "type C" << std::endl;
		return ;
	}
	catch (std::exception &e) {}

	std::cout << "tf are you doing man" << std::endl;
}


int	main(void)
{
	Base *test = generate();
	identify(NULL);
	identify(test);
	if (test != NULL)
		identify(*test);
	delete test;
	return (0);

}