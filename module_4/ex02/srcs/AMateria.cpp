/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:52:29 by mpitot            #+#    #+#             */
/*   Updated: 2024/10/13 23:04:45 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/* Constructors ************************************************************* */
AMateria::AMateria() : _type("undefined") {}

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::AMateria(AMateria const &src) : _type(src._type) {}

AMateria::~AMateria() {}

/* Operators **************************************************************** */
AMateria &AMateria::operator=(AMateria const &src)
{
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

/* Getters ****************************************************************** */
const std::string &AMateria::getType() const
{
	return (this->_type);
}

/* Setters ****************************************************************** */
void AMateria::setType(const std::string &type)
{
	this->_type = type;
}
