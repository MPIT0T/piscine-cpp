/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:28:29 by mpitot            #+#    #+#             */
/*   Updated: 2024/10/08 12:57:19 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

/* Constructors ************************************************************* */
Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(Cat const& src) : Animal(src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_brain = new Brain(*src._brain);
	this->_type = src._type;
}

/* Destructor *************************************************************** */
Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
}

/* Operators **************************************************************** */
Cat&	Cat::operator=(Cat const& src)
{
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &src)
	{
		delete this->_brain;
		this->_brain = new Brain(*src._brain);
		this->_type = src._type;
	}
	return (*this);
}

/* Actions ****************************************************************** */
void	Cat::makeSound() const
{
	std::cout << "\"Miaouu\"" << std::endl;
}
