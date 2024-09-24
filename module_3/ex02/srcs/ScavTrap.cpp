/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:01:17 by mpitot            #+#    #+#             */
/*   Updated: 2024/09/24 15:22:09 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* Constants **************************************************************** */
const std::string	ScavTrap::SCAVTRAP_BASE_NAME = "default";
const unsigned int	ScavTrap::SCAVTRAP_BASE_HITPOINTS = 100;
const unsigned int	ScavTrap::SCAVTRAP_BASE_ENERGY_POINTS = 50;
const unsigned int	ScavTrap::SCAVTRAP_BASE_ATTACK_DAMAGE = 20;

/* Constructors ************************************************************* */
ScavTrap::ScavTrap()
{
	this->_hitpoints = SCAVTRAP_BASE_HITPOINTS;
	this->_energyPoints = SCAVTRAP_BASE_ENERGY_POINTS;
	this->_attackDamage = SCAVTRAP_BASE_ATTACK_DAMAGE;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	this->_hitpoints = SCAVTRAP_BASE_HITPOINTS;
	this->_energyPoints = SCAVTRAP_BASE_ENERGY_POINTS;
	this->_attackDamage = SCAVTRAP_BASE_ATTACK_DAMAGE;
	std::cout << "ScavTrap " << this->_name << " constructor called" <<
		std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	*this = other;
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

/* Operators **************************************************************** */
ScavTrap &ScavTrap::operator=(const ScavTrap& other)
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
void ScavTrap::attack(const std::string& target)
{
	if (this->_hitpoints == 0 || this->_energyPoints == 0)
		return ;
	std::cout << "ScavTrap " << this->_name << " attacks " << target <<
		", causing " << this->_attackDamage << " points of damage!" <<
		std::endl;
	this->_energyPoints--;
}

void ScavTrap::guardGate()
{
	if (this->_hitpoints == 0)
		return ;
	std::cout << "ScavTrap " << this->_name << " has entered gatekeeper mode" <<
		std::endl;
}

/* Destructor *************************************************************** */
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}
