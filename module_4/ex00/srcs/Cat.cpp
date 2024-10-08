/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:28:29 by mpitot            #+#    #+#             */
/*   Updated: 2024/10/07 11:01:33 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

/* Constructors ************************************************************* */
Cat::Cat()
{
	this->_type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(Cat const& src) : Animal(src)
{
	*this = src;
	std::cout << "Cat copy constructor called" << std::endl;
}

/* Destructor *************************************************************** */
Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

/* Operators **************************************************************** */
Cat&	Cat::operator=(Cat const& src)
{
	if (this != &src)
	{
		this->_type = src._type;
	}
	std::cout << "Cat assignation operator called" << std::endl;
	return (*this);
}

/* Actions ****************************************************************** */
void	Cat::makeSound() const
{
	std::cout << "\"Miaouu\"" << std::endl;
}
