/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:28:12 by mpitot            #+#    #+#             */
/*   Updated: 2024/10/01 17:10:35 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

/* Constructors ************************************************************* */
Animal::Animal() : _type("Undefined")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(Animal const& src)
{
	*this = src;
	std::cout << "Animal copy constructor called" << std::endl;
}

/* Operators **************************************************************** */
Animal&	Animal::operator=(Animal const& src)
{
	if (this != &src)
	{
		_type = src._type;
	}
	std::cout << "Animal assignation operator called" << std::endl;
	return *this;
}

/* Destructors ************************************************************** */
Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

/* Actions ****************************************************************** */
void	Animal::makeSound() const
{
	std::cout << " makes \"some indescribables\" sounds" << std::endl;
}

/* Getters ****************************************************************** */
std::string	Animal::getType() const
{
	return _type;
}
