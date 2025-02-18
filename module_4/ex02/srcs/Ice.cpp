/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:59:54 by mpitot            #+#    #+#             */
/*   Updated: 2024/10/14 09:25:50 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

/* Constructors ************************************************************* */
Ice::Ice() : AMateria("ice") {}

Ice::Ice(std::string const &type) : AMateria(type) {}

Ice::Ice(Ice const &src) : AMateria(src) {}

Ice::~Ice() {}

/* Operators **************************************************************** */
Ice		&Ice::operator=(Ice const &src)
{
	if (this != &src)
		this->setType(src.getType());
	return (*this);
}

/* Methods ****************************************************************** */
AMateria	*Ice::clone() const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}