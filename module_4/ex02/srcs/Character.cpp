/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:29:09 by mpitot            #+#    #+#             */
/*   Updated: 2024/10/14 09:46:59 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/* Constructors ************************************************************* */
Character::Character() : _name("undefined") {}

Character::Character(std::string const &name) : _name(name) {}

Character::Character(Character const &src) : _name(src._name) {}

Character::~Character() {}

/* Operators **************************************************************** */
Character &Character::operator=(Character const &src)
{
	if (this != &src)
		this->_name = src._name;
	return (*this);
}

/* Getters ****************************************************************** */
const std::string &Character::getName() const
{
	return (this->_name);
}

/* Setters ****************************************************************** */
void Character::setName(const std::string &name)
{
	this->_name = name;
}

void Character::equip(AMateria *m)
{
	int i = 0;

	while (i < 4 && this->_inventory[i])
		i++;
	if (i < 4)
		this->_inventory[i] = m;
}

void Character::unequip(int i)
{
	if (i >= 0 && i < 4)
		this->_inventory[i] = NULL;
}

/* Methods ****************************************************************** */
void Character::use(int i, ICharacter &target)
{
	if (i >= 0 && i < 4 && this->_inventory[i])
		this->_inventory[i]->use(target);
}
