/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:59:45 by mpitot            #+#    #+#             */
/*   Updated: 2024/10/14 09:22:50 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

/* Constructors ************************************************************* */
Cure::Cure() : AMateria("cure") {}

Cure::Cure(std::string const &type) : AMateria(type) {}

Cure::Cure(Cure const &src) : AMateria(src) {}

Cure::~Cure() {}

/* Operators **************************************************************** */
Cure		&Cure::operator=(Cure const &src)
{
	if (this != &src)
		this->setType(src.getType());
	return (*this);
}

/* Methods ****************************************************************** */
AMateria	*Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals" << target.getName() << "'s wounds *" << std::endl;
}

