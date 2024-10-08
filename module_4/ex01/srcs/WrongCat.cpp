/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:28:57 by mpitot            #+#    #+#             */
/*   Updated: 2024/10/07 14:06:10 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

/* Constructors ************************************************************* */

WrongCat::WrongCat()
{
	this->_type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal(src)
{
	*this = src;
	std::cout << "WrongCat copy constructor called" << std::endl;
}

/* Destructor *************************************************************** */

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

/* Operators **************************************************************** */

WrongCat	&WrongCat::operator=(WrongCat const &src)
{
	if (this != &src)
	{
		this->_type = src._type;
	}
	std::cout << "WrongCat assignation operator called" << std::endl;
	return (*this);
}

/* Actions ****************************************************************** */

void	WrongCat::makeSound() const
{
	std::cout << "\"Wrong Miaou\"" << std::endl;
}
