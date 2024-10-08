/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:28:48 by mpitot            #+#    #+#             */
/*   Updated: 2024/10/07 14:25:57 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

/* Constructors ************************************************************* */

WrongAnimal::WrongAnimal()
{
	this->_type = "Wrong Undefined";
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const& src)
{
	*this = src;
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

/* Destructor *************************************************************** */

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

/* Operators **************************************************************** */

WrongAnimal&	WrongAnimal::operator=(WrongAnimal const& src)
{
	if (this != &src)
	{
		this->_type = src._type;
	}
	std::cout << "WrongAnimal assignation operator called" << std::endl;
	return (*this);
}

/* Actions ****************************************************************** */

void	WrongAnimal::makeSound() const
{
	std::cout << "\"Wrong indescribables noises\"" << std::endl;
}

/* Getters ****************************************************************** */

std::string	WrongAnimal::getType() const
{
	return (this->_type);
}

/* Setters ****************************************************************** */

void	WrongAnimal::setType(std::string type)
{
	this->_type = type;
}
