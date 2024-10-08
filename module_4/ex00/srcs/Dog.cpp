/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:28:37 by mpitot            #+#    #+#             */
/*   Updated: 2024/10/07 10:57:56 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

/* Constructors ************************************************************* */

Dog::Dog()
{
	this->_type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(Dog const& src) : Animal(src)
{
	*this = src;
	std::cout << "Dog copy constructor called" << std::endl;
}

/* Destructor *************************************************************** */

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

/* Operators **************************************************************** */

Dog&	Dog::operator=(Dog const& src)
{
	if (this != &src)
	{
		this->_type = src._type;
	}
	std::cout << "Dog assignation operator called" << std::endl;
	return (*this);
}

/* Actions ****************************************************************** */

void	Dog::makeSound() const
{
	std::cout << "\"Wouf Wouf\"" << std::endl;
}
