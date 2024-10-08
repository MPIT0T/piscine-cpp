/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:28:12 by mpitot            #+#    #+#             */
/*   Updated: 2024/10/07 14:25:40 by mpitot           ###   ########.fr       */
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
		this->_type = src._type;
	}
	std::cout << "Animal assignation operator called" << std::endl;
	return (*this);
}

/* Destructors ************************************************************** */
Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

/* Actions ****************************************************************** */
void	Animal::makeSound() const
{
	std::cout << "\"indescribables noises\"" << std::endl;
}

/* Getters ****************************************************************** */
std::string	Animal::getType() const
{
	return (this->_type);
}

/* Setters ****************************************************************** */
void	Animal::setType(std::string type)
{
	this->_type = type;
}
