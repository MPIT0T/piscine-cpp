/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:28:37 by mpitot            #+#    #+#             */
/*   Updated: 2024/10/08 12:57:19 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

/* Constructors ************************************************************* */

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(Dog const& src) : Animal(src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->_brain = new Brain(*src._brain);
	this->_type = src._type;
}

/* Destructor *************************************************************** */

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
}

/* Operators **************************************************************** */

Dog&	Dog::operator=(Dog const& src)
{
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &src)
	{
		delete this->_brain;
		this->_brain = new Brain(*src._brain);
		this->_type = src._type;
	}
	return (*this);
}

/* Actions ****************************************************************** */

void	Dog::makeSound() const
{
	std::cout << "\"Wouf Wouf\"" << std::endl;
}
