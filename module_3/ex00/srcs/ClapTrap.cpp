/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:42:32 by mpitot            #+#    #+#             */
/*   Updated: 2024/09/23 15:01:41 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* Constants **************************************************************** */

const std::string		ClapTrap::CLAPTRAP_BASE_NAME = "Steve";
const unsigned int		ClapTrap::CLAPTRAP_BASE_HITPOINTS = 10;
const unsigned int		ClapTrap::CLAPTRAP_BASE_ENERGY_POINTS = 10;
const unsigned int		ClapTrap::CLAPTRAP_BASE_ATTACK_DAMAGE = 1;

/* Constructors ************************************************************* */
ClapTrap::ClapTrap() :
	_name(CLAPTRAP_BASE_NAME),
	_hitpoints(CLAPTRAP_BASE_HITPOINTS),
	_energyPoints(CLAPTRAP_BASE_ENERGY_POINTS),
	_attackDamage(CLAPTRAP_BASE_ATTACK_DAMAGE)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) :
	_name(name),
	_hitpoints(CLAPTRAP_BASE_HITPOINTS),
	_energyPoints(CLAPTRAP_BASE_ENERGY_POINTS),
	_attackDamage(CLAPTRAP_BASE_ATTACK_DAMAGE)
{
	std::cout << "ClapTrap name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

/* Operators **************************************************************** */
ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitpoints = other._hitpoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

/* Actions ****************************************************************** */
void ClapTrap::attack(const std::string &target)
{
	if (_energyPoints == 0 || _hitpoints == 0)
		return ;
	std::cout << "ClapTrap " << this->_name << " attacks " << target <<
		", causing " << this->_attackDamage << " points of damage!" <<
		std::endl;
	_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitpoints < amount)
		amount = this->_hitpoints;
	std::cout << "ClapTrap " << this->_name << " takes " << amount <<
		" points of damage!" << std::endl;
	this->_hitpoints -= amount;
	if (this->_hitpoints == 0)
		std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints == 0)
		return ;
	std::cout << "ClapTrap " << this->_name << " repairs " << amount <<
		" points of damage!" << std::endl;
	this->_hitpoints += amount;
	this->_energyPoints--;
}

/* Destructor *************************************************************** */
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}
